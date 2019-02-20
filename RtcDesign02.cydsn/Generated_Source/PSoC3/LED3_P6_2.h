/*******************************************************************************
* File Name: LED3_P6_2.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_LED3_P6_2_H) /* Pins LED3_P6_2_H */
#define CY_PINS_LED3_P6_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED3_P6_2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED3_P6_2_Write(uint8 value) ;
void    LED3_P6_2_SetDriveMode(uint8 mode) ;
uint8   LED3_P6_2_ReadDataReg(void) ;
uint8   LED3_P6_2_Read(void) ;
uint8   LED3_P6_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED3_P6_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LED3_P6_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LED3_P6_2_DM_RES_UP          PIN_DM_RES_UP
#define LED3_P6_2_DM_RES_DWN         PIN_DM_RES_DWN
#define LED3_P6_2_DM_OD_LO           PIN_DM_OD_LO
#define LED3_P6_2_DM_OD_HI           PIN_DM_OD_HI
#define LED3_P6_2_DM_STRONG          PIN_DM_STRONG
#define LED3_P6_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LED3_P6_2_MASK               LED3_P6_2__MASK
#define LED3_P6_2_SHIFT              LED3_P6_2__SHIFT
#define LED3_P6_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED3_P6_2_PS                     (* (reg8 *) LED3_P6_2__PS)
/* Data Register */
#define LED3_P6_2_DR                     (* (reg8 *) LED3_P6_2__DR)
/* Port Number */
#define LED3_P6_2_PRT_NUM                (* (reg8 *) LED3_P6_2__PRT) 
/* Connect to Analog Globals */                                                  
#define LED3_P6_2_AG                     (* (reg8 *) LED3_P6_2__AG)                       
/* Analog MUX bux enable */
#define LED3_P6_2_AMUX                   (* (reg8 *) LED3_P6_2__AMUX) 
/* Bidirectional Enable */                                                        
#define LED3_P6_2_BIE                    (* (reg8 *) LED3_P6_2__BIE)
/* Bit-mask for Aliased Register Access */
#define LED3_P6_2_BIT_MASK               (* (reg8 *) LED3_P6_2__BIT_MASK)
/* Bypass Enable */
#define LED3_P6_2_BYP                    (* (reg8 *) LED3_P6_2__BYP)
/* Port wide control signals */                                                   
#define LED3_P6_2_CTL                    (* (reg8 *) LED3_P6_2__CTL)
/* Drive Modes */
#define LED3_P6_2_DM0                    (* (reg8 *) LED3_P6_2__DM0) 
#define LED3_P6_2_DM1                    (* (reg8 *) LED3_P6_2__DM1)
#define LED3_P6_2_DM2                    (* (reg8 *) LED3_P6_2__DM2) 
/* Input Buffer Disable Override */
#define LED3_P6_2_INP_DIS                (* (reg8 *) LED3_P6_2__INP_DIS)
/* LCD Common or Segment Drive */
#define LED3_P6_2_LCD_COM_SEG            (* (reg8 *) LED3_P6_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED3_P6_2_LCD_EN                 (* (reg8 *) LED3_P6_2__LCD_EN)
/* Slew Rate Control */
#define LED3_P6_2_SLW                    (* (reg8 *) LED3_P6_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED3_P6_2_PRTDSI__CAPS_SEL       (* (reg8 *) LED3_P6_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED3_P6_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED3_P6_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED3_P6_2_PRTDSI__OE_SEL0        (* (reg8 *) LED3_P6_2__PRTDSI__OE_SEL0) 
#define LED3_P6_2_PRTDSI__OE_SEL1        (* (reg8 *) LED3_P6_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED3_P6_2_PRTDSI__OUT_SEL0       (* (reg8 *) LED3_P6_2__PRTDSI__OUT_SEL0) 
#define LED3_P6_2_PRTDSI__OUT_SEL1       (* (reg8 *) LED3_P6_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED3_P6_2_PRTDSI__SYNC_OUT       (* (reg8 *) LED3_P6_2__PRTDSI__SYNC_OUT) 


#if defined(LED3_P6_2__INTSTAT)  /* Interrupt Registers */

    #define LED3_P6_2_INTSTAT                (* (reg8 *) LED3_P6_2__INTSTAT)
    #define LED3_P6_2_SNAP                   (* (reg8 *) LED3_P6_2__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LED3_P6_2_H */


/* [] END OF FILE */
