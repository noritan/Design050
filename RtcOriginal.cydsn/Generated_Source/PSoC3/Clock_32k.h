/*******************************************************************************
* File Name: Clock_32k.h
* Version 2.0
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock_32k_H)
#define CY_CLOCK_Clock_32k_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock_32k_Start(void) ;
void Clock_32k_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock_32k_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock_32k_StandbyPower(uint8 state) ;
void Clock_32k_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock_32k_GetDividerRegister(void) ;
void Clock_32k_SetModeRegister(uint8 modeBitMask) ;
void Clock_32k_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock_32k_GetModeRegister(void) ;
void Clock_32k_SetSourceRegister(uint8 clkSource) ;
uint8 Clock_32k_GetSourceRegister(void) ;
#if defined(Clock_32k__CFG3)
void Clock_32k_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock_32k_GetPhaseRegister(void) ;
#endif /* defined(Clock_32k__CFG3) */

#define Clock_32k_Enable()                       Clock_32k_Start()
#define Clock_32k_Disable()                      Clock_32k_Stop()
#define Clock_32k_SetDivider(clkDivider)         Clock_32k_SetDividerRegister(clkDivider, 1)
#define Clock_32k_SetDividerValue(clkDivider)    Clock_32k_SetDividerRegister((clkDivider) - 1, 1)
#define Clock_32k_SetMode(clkMode)               Clock_32k_SetModeRegister(clkMode)
#define Clock_32k_SetSource(clkSource)           Clock_32k_SetSourceRegister(clkSource)
#if defined(Clock_32k__CFG3)
#define Clock_32k_SetPhase(clkPhase)             Clock_32k_SetPhaseRegister(clkPhase)
#define Clock_32k_SetPhaseValue(clkPhase)        Clock_32k_SetPhaseRegister((clkPhase) + 1)
#endif /* defined(Clock_32k__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock_32k_CLKEN              (* (reg8 *) Clock_32k__PM_ACT_CFG)
#define Clock_32k_CLKEN_PTR          ((reg8 *) Clock_32k__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock_32k_CLKSTBY            (* (reg8 *) Clock_32k__PM_STBY_CFG)
#define Clock_32k_CLKSTBY_PTR        ((reg8 *) Clock_32k__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock_32k_DIV_LSB            (* (reg8 *) Clock_32k__CFG0)
#define Clock_32k_DIV_LSB_PTR        ((reg8 *) Clock_32k__CFG0)
#define Clock_32k_DIV_PTR            ((reg16 *) Clock_32k__CFG0)

/* Clock MSB divider configuration register. */
#define Clock_32k_DIV_MSB            (* (reg8 *) Clock_32k__CFG1)
#define Clock_32k_DIV_MSB_PTR        ((reg8 *) Clock_32k__CFG1)

/* Mode and source configuration register */
#define Clock_32k_MOD_SRC            (* (reg8 *) Clock_32k__CFG2)
#define Clock_32k_MOD_SRC_PTR        ((reg8 *) Clock_32k__CFG2)

#if defined(Clock_32k__CFG3)
/* Analog clock phase configuration register */
#define Clock_32k_PHASE              (* (reg8 *) Clock_32k__CFG3)
#define Clock_32k_PHASE_PTR          ((reg8 *) Clock_32k__CFG3)
#endif /* defined(Clock_32k__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock_32k_CLKEN_MASK         Clock_32k__PM_ACT_MSK
#define Clock_32k_CLKSTBY_MASK       Clock_32k__PM_STBY_MSK

/* CFG2 field masks */
#define Clock_32k_SRC_SEL_MSK        Clock_32k__CFG2_SRC_SEL_MASK
#define Clock_32k_MODE_MASK          (~(Clock_32k_SRC_SEL_MSK))

#if defined(Clock_32k__CFG3)
/* CFG3 phase mask */
#define Clock_32k_PHASE_MASK         Clock_32k__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock_32k__CFG3) */

#endif /* CY_CLOCK_Clock_32k_H */


/* [] END OF FILE */
