
#ifndef __UART_H__
#define __UART_H__

#include <gd32f10x.h>
#include "gd32f103r_eval.h"


#define FRAME_HEAD 0xA5





void send_btn_change_to_cpu(uint8_t whichkey,uint8_t status);
#endif
