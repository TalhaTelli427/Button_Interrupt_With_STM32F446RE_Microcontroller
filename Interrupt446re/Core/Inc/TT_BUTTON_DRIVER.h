/*
 * TT_BUTTON_DRIVER.h
 *
 *  Created on: Mar 31, 2023
 *      Author: talha
 */

#ifndef INC_TT_BUTTON_DRIVER_H_
#define INC_TT_BUTTON_DRIVER_H_
#include "main.h"
extern int counter;

void wait(void);
void button_init(void);
int button_get_state(void);
void button_int_init(void);



#endif /* INC_TT_BUTTON_DRIVER_H_ */
