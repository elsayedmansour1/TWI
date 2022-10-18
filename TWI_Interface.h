/*
 * TWI_Interface.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Elsayed.Mansour
 */

#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_voidMasterInit(void);
void TWI_voidStartCondition(void);
void TWI_voidSendSlaveAddressWrite(u8 copy_u8SlaveAddress);
void TWI_voidSendSlaveAddressRead(u8 copy_u8SlaveAddress);
void TWI_voidMasterSendData(u8 copy_u8Data);
void TWI_voidMasterReceiveData(u8 *copy_u8Data);
void TWI_voidStopCondition(void);

#endif /* TWI_INTERFACE_H_ */
