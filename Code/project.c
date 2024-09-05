/*
 * File:   project.c
 * Author: ah427
 *
 * Created on 21 ?????, 2024, 08:41 ?
 */


#include <xc.h>
#include "project.h"

#define _XTAL_FREQ 80000000UL

uint8 number_bcd = 0; 
// 23
//0000 0011
//0010 0000
void initialization(void);

void main(void) {
    initialization();
    for(uint8 number=0; number<99; number++){
        number_bcd = (((uint8)number%10) | (((uint8)number/10) << 4)); 
        gpio_port_write_logic(GPIO_PORTC, number_bcd);
        __delay_ms(20);
    }    
    
    return;
}

void initialization(void){ 
    gpio_port_direction_initialize(GPIO_PORTC, GPIO_OUTPUT);
    gpio_port_direction_initialize(GPIO_PORTD, GPIO_OUTPUT);

    gpio_port_write_logic(GPIO_PORTC, 0x00);
}
