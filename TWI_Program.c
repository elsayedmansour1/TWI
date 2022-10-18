/*
 * TWI_Program.c
 *
 *  Created on: Oct 16, 2022
 *      Author: Elsayed.Mansour
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TWI_Register.h"
#include"TWI_Interface.h"


void TWI_voidMasterInit(void)
{

    TWBR = 0x02;
	TWSR = 0x00;
	TWAR = 0b00000010; // my address = 0x01 :)

	SET_BIT(TWCR,2);
}
void TWI_voidStartCondition(void)
{
	//set start condition
	SET_BIT(TWCR,5);
	//make sure flag clear
	SET_BIT(TWCR,7);
	//enable TWI
	SET_BIT(TWCR,2);
	//wait until flag be set
	while(GET_BIT(TWCR,7)==0);
	//make sure return state for start condition
	if((TWSR & 0xf8) !=0x08)
	{
		//TWDR=0x50;
	}
}
void TWI_voidSendSlaveAddressWrite(u8 copy_u8SlaveAddress)
{
	//write slave address
	TWDR=copy_u8SlaveAddress<<1;
	//set write operation
	CLR_BIT(TWDR,0);
	//make sure flag be clear
	SET_BIT(TWCR,7);
	//enable TWI
	SET_BIT(TWCR,2);
	//wait until flag be set
	while(!GET_BIT(TWCR,7));
	//make sure return state for slave with write
	if((TWSR &0xf8)!=0x18)
	{
			//for error state when you need it
	}

}
void TWI_voidSendSlaveAddressRead(u8 copy_u8SlaveAddress)
{
	//CLR bit of start condition
	CLR_BIT(TWCR,5);
	//write slave address
	TWDR=copy_u8SlaveAddress<<1;
	//set Read operation
	SET_BIT(TWDR,0);
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//wait until flag be set
	while(!GET_BIT(TWCR,7));
	//make sure return state for slave with write
	if((TWSR &0xf8)!=0x40)
	{
			//for error state when you need it
	}
}
void TWI_voidMasterSendData(u8 copy_u8Data)
{
	//Write your data
	TWDR=copy_u8Data;
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//enable TWI
	SET_BIT(TWCR,2);
	//wait until flag be clear
	while(!GET_BIT(TWCR,7));
	//make sure return state for master send data
	if((TWSR &0xf8)!=0x40)
	{
			//for error state when you need it
	}
}
void TWI_voidMasterReceiveData(u8 *copy_u8Data)
{

	//make sure flag is clear
	SET_BIT(TWCR,7);
	//wait until flag be clear
	while(!GET_BIT(TWCR,7));
	//make sure return state for master send data
	if((TWSR &0xf8)!=0x50)
	{
			//for error state when you need it
	}
	else
	{
		*copy_u8Data=TWDR;
	}
}
void TWI_voidStopCondition(void)
{
	//make sure flag is clear
	SET_BIT(TWCR,7);
	//set Stop condition
	SET_BIT(TWCR,4);
	//enable TWI
	SET_BIT(TWCR,2);
}
