
#include <gd32f10x.h>
#include "systick.h"
#include "gd32f103r_eval.h"
#include "btns.h"
#include "stdio.h"


const char* g_build_time_str = "Buildtime :"__DATE__" "__TIME__;   //获得编译时间
/*
	2022-03-17 设置系统时钟为8M，没有倍频了！！！
	
	任务就是1.按键扫描，2把按键的值通过串口上报
	
	15 个按键，其中有一个是本控，带自锁，只有这个按键被按下时，其他按键才生效
*/


static void work_led_init(void)
{  //PA8 ,低电平点亮
	rcu_periph_clock_enable(RCU_GPIOA);
	
	gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_8);
}

void work_led_toggle(void)
{
	if(gpio_output_bit_get(GPIOA, GPIO_PIN_8))
	{
		/* reset GPIO pin bit */
		gpio_bit_reset(GPIOA, GPIO_PIN_8);
	}
	else
	{
		/* set GPIO pin bit */
		gpio_bit_set(GPIOA, GPIO_PIN_8);
	}
}


static void init_board(void)
{	
	//1. 设置中断分组。
	nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);
	
	//2. 设置systick中断
	systick_config();
	
	//3. 设置systick时钟源，为1M，即1us计时一次，1000次即1ms
	//systick_clksource_set(SYSTICK_CLKSOURCE_HCLK_DIV8); 	//用于按键消抖，或延时
	
	//4. 配置按键为io查询模式
	gd_all_keys_init(KEY_MODE_GPIO);
	
	//5. 初始化串口1，调试串口
	gd_eval_com_init(EVAL_COM0);   //115200,8N1
	//6. 初始化串口2，上传按键信息
	gd_eval_com_init(EVAL_COM1);   //115200,8N1
	
	//7. 工作灯，500ms翻转一次
	work_led_init();
}




int main()
{
	init_board();
	
	printf("%s\n\r", g_build_time_str);
	printf("BoardInit done! 2022-04-24\n\r");

	
	while(1)
	{
		btn_handle();   //按键处理
	}
}

