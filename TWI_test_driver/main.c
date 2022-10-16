/*
 * main.c
 *
 *  Created on: Oct 16, 2022
 *      Author: Elsayed.Mansour
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI_Interface.h"

int main(void)
{
	TWI_voidMasterInit();
	while(1)
	{
		TWI_voidStartCondition();
		TWI_voidSendSlaveAddressWrite(1);
		TWI_voidMasterSendData('a');
		TWI_voidStopCondition();
	}

	return 0;
}
