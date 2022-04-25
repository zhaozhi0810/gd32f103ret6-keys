
#ifndef __UART_H__
#define __UART_H__

#include <gd32f10x.h>
#include "gd32f103r_eval.h"


#define FRAME_HEAD 0xA5



#define  DEBUG_PRINTF    //�������һЩ������Ϣ
#define  MY_DEBUG        //�������һЩ������Ϣ������ʹ��ʱ����Ҫ

#ifdef DEBUG_PRINTF
  #define DBG_PRINTF(fmt, args...)  \
  do{\
    printf("<<File:%s  Line:%d  Function:%s>> ", __FILE__, __LINE__, __FUNCTION__);\
    printf(fmt, ##args);\
  }while(0)
#else
  #define DBG_PRINTF(fmt, args...)   
#endif


  
#ifdef MY_DEBUG
#define MY_PRINTF(fmt, args...)  \
  do{\
	printf("<<MY_DEBUG>> ");\
    printf(fmt, ##args);\
  }while(0)
#else
  #define MY_PRINTF(fmt, args...)   
#endif




void send_btn_change_to_cpu(uint8_t whichkey,uint8_t status);
void Com_Debug_Rne_Int_Handle(void);
#endif
