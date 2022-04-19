

#include <gd32f10x.h>
#include "uart.h"
#include "gd32f103r_eval.h"
#include "stdio.h"
/*
	两个串口，串口1（调试），和串口2（发送数据到cpu）
	
	串口函数没有设计接收函数
	两个波特率都是115200，8N1
	
*/

#define DEBUG_COM_NUM 0
#define TOCPU_COM_NUM 1


static rcu_periph_enum COM_CLK[COMn] = {EVAL_COM0_CLK, EVAL_COM1_CLK};
static uint32_t COM_TX_PIN[COMn] = {EVAL_COM0_TX_PIN, EVAL_COM1_TX_PIN};
static uint32_t COM_RX_PIN[COMn] = {EVAL_COM0_RX_PIN, EVAL_COM1_RX_PIN};
static uint32_t COM_GPIO_PORT[COMn] = {EVAL_COM0_GPIO_PORT, EVAL_COM1_GPIO_PORT};
static rcu_periph_enum COM_GPIO_CLK[COMn] = {EVAL_COM0_GPIO_CLK, EVAL_COM1_GPIO_CLK};

static uint8_t uart_inited = 0 ; //bit0,bit1有效，为1表示初始化了，为0表示未初始化

/*!
    \brief      configure COM port
    \param[in]  com: COM on the board
      \arg        EVAL_COM0: COM0 on the board
      \arg        EVAL_COM1: COM1 on the board
    \param[out] none
    \retval     none
*/
void gd_eval_com_init(uint32_t com)
{
    uint32_t com_id = 0U;
    if(EVAL_COM0 == com){
        com_id = 0U;
    }else if(EVAL_COM1 == com){
        com_id = 1U;
    }
    
    /* enable GPIO clock */
    rcu_periph_clock_enable(COM_GPIO_CLK[com_id]);

    /* enable USART clock */
    rcu_periph_clock_enable(COM_CLK[com_id]);

    /* connect port to USARTx_Tx */
    gpio_init(COM_GPIO_PORT[com_id], GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, COM_TX_PIN[com_id]);

    /* connect port to USARTx_Rx */
    gpio_init(COM_GPIO_PORT[com_id], GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, COM_RX_PIN[com_id]);

    /* USART configure */
    usart_deinit(com);
    usart_baudrate_set(com, 115200U);
    usart_word_length_set(com, USART_WL_8BIT);
    usart_stop_bit_set(com, USART_STB_1BIT);
    usart_parity_config(com, USART_PM_NONE);
    usart_hardware_flow_rts_config(com, USART_RTS_DISABLE);
    usart_hardware_flow_cts_config(com, USART_CTS_DISABLE);
    usart_receive_config(com, USART_RECEIVE_ENABLE);
    usart_transmit_config(com, USART_TRANSMIT_ENABLE);
    usart_enable(com);
	
	uart_inited |= 1<<com_id;
}



static void Uart_Tx(uint8_t com_no, uint8_t ch)
{
	const uint32_t com[] = {EVAL_COM0,EVAL_COM1};
    
	if(com_no > TOCPU_COM_NUM){
        return;
    }
	
	if(uart_inited & (1<<com_no))   //uart没有初始化
	{
		while(RESET == usart_flag_get(com[com_no], USART_FLAG_TBE));
		usart_data_transmit(com[com_no], (uint8_t)ch); 
	}	
}

//调试串口输出printf
/* retarget the C library printf function to the USART */
int fputc(int ch, FILE *f)
{
	Uart_Tx(DEBUG_COM_NUM, ch);   //从串口0输出
    return ch;
}





//发送一段字符
//com 表示从哪个端口发出
static void Uart_Tx_String(uint8_t com_no, uint8_t *str, uint8_t length)
{
	uint8_t i;
	
	for(i = 0; i < length; i++)
		Uart_Tx(com_no,str[i]);
}



uint8_t checksum(uint8_t *buf, uint8_t len)
{
	uint8_t sum;
	uint8_t i;

	for(i=0,sum=0; i<len; i++)
		sum += buf[i];

	return sum;
}



//校验数据
int32_t verify_data(uint8_t *data,uint8_t len)
{
	uint8_t check;
	int32_t ret = -1;
	
	if(data == NULL)
		return -1;
	
	//读取原数据中的校验值
	check = data[len - 1];
	
	//重新计算校验值
	if(check==checksum(data,len - 1))
		ret = 0;
	
	return ret;
}





//发送按键的数据到cpu
//whichkey 0xe8 - 0xf9
//status 0 or 1 松开或者按下
void send_btn_change_to_cpu(uint8_t whichkey,uint8_t status)
{
	unsigned char buf[5];  	
	
	if(!(uart_inited & 2))   //串口没初始化
		return ;
	
	buf[0] = FRAME_HEAD;  //帧头	
	buf[1] = whichkey;    //
	buf[2] = status;    //
	//crc重新计算
	buf[3] = buf[0] + buf[1] + buf[2];  //校验和，0,1,2相加.
	
	Uart_Tx_String(TOCPU_COM_NUM,buf, 4);   //com_frame_t并没有包含数据头，所以加1个字节	
}


