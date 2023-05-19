/*
 * TT_LED_DRIVER.c
 *
 *  Created on: Mar 31, 2023
 *      Author: talha
 */
#include "main.h"

void Led_init(){
	  RCC->AHB1ENR |=(1<<0);
	  GPIOA->MODER|=(1<<10);
	  GPIOA->MODER &=~(1<<11);
	  GPIOA->OTYPER &=~(1<<5);
	  GPIOA->OSPEEDR &=~(1<<10);
	  GPIOA->OSPEEDR &=~(1<<11);
}

void Led_OFF(){

	  GPIOA->ODR&=~(1<<5);

}

void Led_On(){

	  GPIOA->ODR|=(1<<5);
}

void LED_Toggle(){

	  GPIOA->ODR^=(1<<5);

}
