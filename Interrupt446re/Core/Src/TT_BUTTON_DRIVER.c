/*
 * TT_BUTTON_DRIVER.c
 *
 *  Created on: Mar 31, 2023
 *      Author: talha
 */
// Değişken tanuımlamalarda yöntem belirle
#include <TT_BUTTON_DRIVER.h>
#include "main.h"
#include "TT_LED_DRIVER.h"

 int counter=0;

void button_init(void){
	  RCC->AHB1ENR |=(1<<2);
	  GPIOC->MODER &=~(1<<26);
	  GPIOC->MODER &=~(1<<27);
}

void wait(void){

	if(counter==0){
		HAL_Delay(100);
	}
	else if(counter==1){
		HAL_Delay(200);
	}
	else if(counter==2){
		HAL_Delay(500);
	}
	else if(counter==3){
		HAL_Delay(1000);
	}

	else if(counter>3){
		counter=0;
	}



}




void button_int_init(void){

	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_SYSCFG_CLK_ENABLE();

	GPIOC->MODER &=  ~(3UL<<26);
	GPIOC->PUPDR &=  ~(3UL<<26);

	SYSCFG->EXTICR[3] |= 0x20;

	EXTI->IMR |= EXTI_IMR_IM13;
	EXTI->FTSR|= EXTI_FTSR_TR13;

	NVIC_SetPriority(EXTI15_10_IRQn,1);
	NVIC_EnableIRQ(EXTI15_10_IRQn);


}

void EXTI15_10_IRQHandler(void){

	if((EXTI->PR & EXTI_PR_PR13)== (EXTI_PR_PR13)){


		EXTI->PR |= EXTI_PR_PR13;
		counter++;


	}
    }



int button_get_state(void){

	if (!(GPIOC->IDR &(1<<13))){

		return 1;
		}

	else{

		return 0;}
}
