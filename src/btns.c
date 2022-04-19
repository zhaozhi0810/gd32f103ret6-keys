

#include "btns.h"
#include <gd32f10x.h>
#include "systick.h"
#include "gd32f103r_eval.h"
#include "uart.h"
#include "stdio.h"

/*
	按键扫描程序
	
	15个按键
	
	对应的接口分别为
	PB8-PB15 --- >   KEY1->KEY8
	PC0-PC6  --- >   KEY9->KEY15
	
	本控按键，按下才能上报。
	
	按键扫描程序，10ms扫描一次。
	根据本控键，控制是否上报，按下和松开都会上报
	不支持多按键同时按下的情况
*/




static BTN_INFO btn[KEY_MAX];

static uint8_t btn_press_num = 0;

#define BENKONG_KEY 1   //（请填 1-15）现在不知道是哪个，先假设为第一个吧！！！！！



//配置所有的按键
void gd_all_keys_init(keymode_typedef_enum key_mode)
{
	uint32_t pin;
	
	//1. 时钟使能
	rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOC);
		
	//2. 设置为输入模式	
	pin = BITS(8,15); 
	gpio_init(GPIOB, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_2MHZ, pin);
	pin = BITS(0,6);
	gpio_init(GPIOC, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_2MHZ, pin);
}


//获取按键的值，0-14位表示按键值，1表示按下，0表示松开
static uint16_t gd_all_keys_state_get(void)
{
	uint16_t val,t;
	
	t = gpio_input_port_get(GPIOC);
	val = GET_BITS(t, 0, 6)<<8;
	t = gpio_input_port_get(GPIOB);
	val |= GET_BITS(t, 8, 15);
	
	return ~val & 0x7fff;    //因为按下是低电平，松开是高电平，取一下反
}



/*
	函数调用，按键处理任务
		通过串口上报到3A5000
*/
void btn_handle(void)
{
	if(!btn[BENKONG_KEY-1].value)   //本控没被按下
		return;
	
	if(btn_press_num)
	{
		if(btn_press_num != BENKONG_KEY)   //本控按键不上报
		{		
			if(btn[btn_press_num-1].reportEn == 1)
			{
				btn[btn_press_num-1].reportEn = 0;
				
				//只要按键改变了，就要通知cpu！！！！！！
				send_btn_change_to_cpu(btn_press_num, btn[btn_press_num-1].value);  //按键编码1-15，0表示松开，非0表示按下
				printf("key %d by %s\n",btn_press_num,btn[btn_press_num-1].value?"press":"release");
				//			send_btn_change_to_cpu(btn[btn_press_num-1].code,btn[btn_press_num-1].value?1:0);
			}
		}
		btn_press_num = 0;    //处理结束后清零
	}
}






/*
	按键1-9的扫描
	定时器中断触发扫描，10ms扫一次，30ms
	
	返回值：
		无
*/
void btns_scan(void) // 10ms 调用一次
{
	uint16_t dat;
	uint8_t i;
	
	dat = gd_all_keys_state_get();   //读取按键的状态
	
	for(i=0;i<15;i++)
	{
		if(dat & (1<<i))   //按下是1,松开是0
		{					
			if(btn[i].value == 0)  //没有确定是按下
			{	
				btn[i].pressCnt++;
				if((btn[i].pressCnt >= 3))   //按下计时30ms
				{
					btn[i].value = 1;  //确定被按下了
					btn[i].reportEn = 1;   //按下有效
					btn_press_num = i+1;    //记录被按下的按键 1-18，加1的原因是去掉0
				}
			}
		}
		else //松开的
		{
			btn[i].pressCnt = 0;
			if(btn[i].value == 1)   //之前是按下的
			{
				btn[i].value = 0;    //松开了
				btn[i].reportEn = 1;  //松开有效
				btn_press_num = i+1;    //记录被松开的按键
			}
		}
	}
}




