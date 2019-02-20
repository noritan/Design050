/*******************************************************************************
* File Name: LED4_P6_3.h  
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

#if !defined(CY_PINS_LED4_P6_3_H) /* Pins LED4_P6_3_H */
#define CY_PINS_LED4_P6_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LED4_P6_3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED4_P6_3_Write(uint8 value) ;
void    LED4_P6_3_SetDriveMode(uint8 mode) ;
uint8   LED4_P6_3_ReadDataReg(void) ;
uint8   LED4_P6_3_Read(void) ;
uint8   LED4_P6_3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED4_P6_3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LED4_P6_3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LED4_P6_3_DM_RES_UP          PIN_DM_RES_UP
#define LED4_P6_3_DM_RES_DWN         PIN_DM_RES_DWN
#define LED4_P6_3_DM_OD_LO           PIN_DM_OD_LO
#define LED4_P6_3_DM_OD_HI           PIN_DM_OD_HI
#define LED4_P6_3_DM_STRONG          PIN_DM_STRONG
#define LED4_P6_3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LED4_P6_3_MASK               LED4_P6_3__MASK
#define LED4_P6_3_SHIFT              LED4_P6_3__SHIFT
#define LED4_P6_3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED4_P6_3_PS                     (* (reg8 *) LED4_P6_3__PS)
/* Data Register */
#define LED4_P6_3_DR                     (* (reg8 *) LED4_P6_3__DR)
/* Port Number */
#define LED4_P6_3_PRT_NUM                (* (reg8 *) LED4_P6_3__PRT) 
/* Connect to Analog Globals */                                                  
#define LED4_P6_3_AG                     (* (reg8 *) LED4_P6_3__AG)                       
/* Analog MUX bux enable */
#define LED4_P6_3_AMUX                   (* (reg8 *) LED4_P6_3__AMUX) 
/* Bidirectional Enable */                                                        
#define LED4_P6_3_BIE                    (* (reg8 *) LED4_P6_3__BIE)
/* Bit-mask for Aliased Register Access */
#define LED4_P6_3_BIT_MASK               (* (reg8 *) LED4_P6_3__BIT_MASK)
/* Bypass Enable */
#define LED4_P6_3_BYP                    (* (reg8 *) LED4_P6_3__BYP)
/* Port wide control signals */                                                   
#define LED4_P6_3_CTL                    (* (reg8 *) LED4_P6_3__CTL)
/* Drive Modes */
#define LED4_P6_3_DM0                    (* (reg8 *) LED4_P6_3__DM0) 
#define LED4_P6_3_DM1                    (* (reg8 *) LED4_P6_3__DM1)
#define LED4_P6_3_DM2                    (* (reg8 *) LED4_P6_3__DM2) 
/* Input Buffer Disable Override */
#define LED4_P6_3_INP_DIS                (* (reg8 *) LED4_P6_3__INP_DIS)
/* LCD Common or Segment Drive */
#define LED4_P6_3_LCD_COM_SEG            (* (reg8 *) LED4_P6_3__LCD_COM_SEG)
/* Enable Segment LCD */
#define LED4_P6_3_LCD_EN                 (* (reg8 *) LED4_P6_3__LCD_EN)
/* Slew Rate Control */
#define LED4_P6_3_SLW                    (* (reg8 *) LED4_P6_3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LED4_P6_3_PRTDSI__CAPS_SEL       (* (reg8 *) LED4_P6_3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LED4_P6_3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LED4_P6_3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LED4_P6_3_PRTDSI__OE_SEL0        (* (reg8 *) LED4_P6_3__PRTDSI__OE_SEL0) 
#define LED4_P6_3_PRTDSI__OE_SEL1        (* (reg8 *) LED4_P6_3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LED4_P6_3_PRTDSI__OUT_SEL0       (* (reg8 *) LED4_P6_3__PRTDSI__OUT_SEL0) 
#define LED4_P6_3_PRTDSI__OUT_SEL1       (* (reg8 *) LED4_P6_3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LED4_P6_3_PRTDSI__SYNC_OUT       (* (reg8 *) LED4_P6_3__PRTDSI__SYNC_OUT) 


#if defined(LED4_P6_3__INTSTAT)  /* Interrupt Registers */

    #define LED4_P6_3_INTSTAT                (* (reg8 *) LED4_P6_3__INTSTAT)
    #define LED4_P6_3_SNAP                   (* (reg8 *) LED4_P6_3__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins LED4_P6_3_H */


/* [] END OF FILE */
