/*******************************************************************************
* File Name: Int_SW2.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ISR_Int_SW2_H)
#define CY_ISR_Int_SW2_H

#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Int_SW2_Start(void) ;
void Int_SW2_StartEx(cyisraddress address) ;
void Int_SW2_Stop(void) ;

CY_ISR_PROTO(Int_SW2_Interrupt);

void Int_SW2_SetVector(cyisraddress address) ;
cyisraddress Int_SW2_GetVector(void) ;

void Int_SW2_SetPriority(uint8 priority) ;
uint8 Int_SW2_GetPriority(void) ;

void Int_SW2_Enable(void) ;
uint8 Int_SW2_GetState(void) ;
void Int_SW2_Disable(void) ;

void Int_SW2_SetPending(void) ;
void Int_SW2_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Int_SW2 ISR. */
#define Int_SW2_INTC_VECTOR            ((reg16 *) Int_SW2__INTC_VECT)

/* Address of the Int_SW2 ISR priority. */
#define Int_SW2_INTC_PRIOR             ((reg8 *) Int_SW2__INTC_PRIOR_REG)

/* Priority of the Int_SW2 interrupt. */
#define Int_SW2_INTC_PRIOR_NUMBER      Int_SW2__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Int_SW2 interrupt. */
#define Int_SW2_INTC_SET_EN            ((reg8 *) Int_SW2__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Int_SW2 interrupt. */
#define Int_SW2_INTC_CLR_EN            ((reg8 *) Int_SW2__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Int_SW2 interrupt state to pending. */
#define Int_SW2_INTC_SET_PD            ((reg8 *) Int_SW2__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Int_SW2 interrupt. */
#define Int_SW2_INTC_CLR_PD            ((reg8 *) Int_SW2__INTC_CLR_PD_REG)



#endif /* CY_ISR_Int_SW2_H */


/* [] END OF FILE */
