/*******************************************************************************
* File Name: PWM_SLOW_PM.c
* Version 2.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/
#include "cytypes.h"
#include "PWM_SLOW.h"

static PWM_SLOW_backupStruct PWM_SLOW_backup;


/*******************************************************************************
* Function Name: PWM_SLOW_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_SLOW_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_SLOW_SaveConfig(void) 
{
    
    #if(!PWM_SLOW_UsingFixedFunction)
        #if (CY_PSOC5A)
            PWM_SLOW_backup.PWMUdb = PWM_SLOW_ReadCounter();
            PWM_SLOW_backup.PWMPeriod = PWM_SLOW_ReadPeriod();
            #if (PWM_SLOW_UseStatus)
                PWM_SLOW_backup.InterruptMaskValue = PWM_SLOW_STATUS_MASK;
            #endif /* (PWM_SLOW_UseStatus) */
            
            #if(PWM_SLOW_UseOneCompareMode)
                PWM_SLOW_backup.PWMCompareValue = PWM_SLOW_ReadCompare();
            #else
                PWM_SLOW_backup.PWMCompareValue1 = PWM_SLOW_ReadCompare1();
                PWM_SLOW_backup.PWMCompareValue2 = PWM_SLOW_ReadCompare2();
            #endif /* (PWM_SLOW_UseOneCompareMode) */
            
           #if(PWM_SLOW_DeadBandUsed)
                PWM_SLOW_backup.PWMdeadBandValue = PWM_SLOW_ReadDeadTime();
            #endif /* (PWM_SLOW_DeadBandUsed) */
          
            #if ( PWM_SLOW_KillModeMinTime)
                PWM_SLOW_backup.PWMKillCounterPeriod = PWM_SLOW_ReadKillTime();
            #endif /* ( PWM_SLOW_KillModeMinTime) */
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            #if(!PWM_SLOW_PWMModeIsCenterAligned)
                PWM_SLOW_backup.PWMPeriod = PWM_SLOW_ReadPeriod();
            #endif /* (!PWM_SLOW_PWMModeIsCenterAligned) */
            PWM_SLOW_backup.PWMUdb = PWM_SLOW_ReadCounter();
            #if (PWM_SLOW_UseStatus)
                PWM_SLOW_backup.InterruptMaskValue = PWM_SLOW_STATUS_MASK;
            #endif /* (PWM_SLOW_UseStatus) */
            
            #if(PWM_SLOW_DeadBandMode == PWM_SLOW__B_PWM__DBM_256_CLOCKS || \
                PWM_SLOW_DeadBandMode == PWM_SLOW__B_PWM__DBM_2_4_CLOCKS)
                PWM_SLOW_backup.PWMdeadBandValue = PWM_SLOW_ReadDeadTime();
            #endif /*  deadband count is either 2-4 clocks or 256 clocks */
            
            #if(PWM_SLOW_KillModeMinTime)
                 PWM_SLOW_backup.PWMKillCounterPeriod = PWM_SLOW_ReadKillTime();
            #endif /* (PWM_SLOW_KillModeMinTime) */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(PWM_SLOW_UseControl)
            PWM_SLOW_backup.PWMControlRegister = PWM_SLOW_ReadControlRegister();
        #endif /* (PWM_SLOW_UseControl) */
    #endif  /* (!PWM_SLOW_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_SLOW_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_SLOW_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_SLOW_RestoreConfig(void) 
{
        #if(!PWM_SLOW_UsingFixedFunction)
            #if (CY_PSOC5A)
                /* Interrupt State Backup for Critical Region*/
                uint8 PWM_SLOW_interruptState;
                /* Enter Critical Region*/
                PWM_SLOW_interruptState = CyEnterCriticalSection();
                #if (PWM_SLOW_UseStatus)
                    /* Use the interrupt output of the status register for IRQ output */
                    PWM_SLOW_STATUS_AUX_CTRL |= PWM_SLOW_STATUS_ACTL_INT_EN_MASK;
                    
                    PWM_SLOW_STATUS_MASK = PWM_SLOW_backup.InterruptMaskValue;
                #endif /* (PWM_SLOW_UseStatus) */
                
                #if (PWM_SLOW_Resolution == 8)
                    /* Set FIFO 0 to 1 byte register for period*/
                    PWM_SLOW_AUX_CONTROLDP0 |= (PWM_SLOW_AUX_CTRL_FIFO0_CLR);
                #else /* (PWM_SLOW_Resolution == 16)*/
                    /* Set FIFO 0 to 1 byte register for period */
                    PWM_SLOW_AUX_CONTROLDP0 |= (PWM_SLOW_AUX_CTRL_FIFO0_CLR);
                    PWM_SLOW_AUX_CONTROLDP1 |= (PWM_SLOW_AUX_CTRL_FIFO0_CLR);
                #endif /* (PWM_SLOW_Resolution == 8) */
                /* Exit Critical Region*/
                CyExitCriticalSection(PWM_SLOW_interruptState);
                
                PWM_SLOW_WriteCounter(PWM_SLOW_backup.PWMUdb);
                PWM_SLOW_WritePeriod(PWM_SLOW_backup.PWMPeriod);
                
                #if(PWM_SLOW_UseOneCompareMode)
                    PWM_SLOW_WriteCompare(PWM_SLOW_backup.PWMCompareValue);
                #else
                    PWM_SLOW_WriteCompare1(PWM_SLOW_backup.PWMCompareValue1);
                    PWM_SLOW_WriteCompare2(PWM_SLOW_backup.PWMCompareValue2);
                #endif /* (PWM_SLOW_UseOneCompareMode) */
                
               #if(PWM_SLOW_DeadBandMode == PWM_SLOW__B_PWM__DBM_256_CLOCKS || \
                   PWM_SLOW_DeadBandMode == PWM_SLOW__B_PWM__DBM_2_4_CLOCKS)
                    PWM_SLOW_WriteDeadTime(PWM_SLOW_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
                #if ( PWM_SLOW_KillModeMinTime)
                    PWM_SLOW_WriteKillTime(PWM_SLOW_backup.PWMKillCounterPeriod);
                #endif /* ( PWM_SLOW_KillModeMinTime) */
            #endif /* (CY_PSOC5A) */
            
            #if (CY_PSOC3 || CY_PSOC5LP)
                #if(!PWM_SLOW_PWMModeIsCenterAligned)
                    PWM_SLOW_WritePeriod(PWM_SLOW_backup.PWMPeriod);
                #endif /* (!PWM_SLOW_PWMModeIsCenterAligned) */
                PWM_SLOW_WriteCounter(PWM_SLOW_backup.PWMUdb);
                #if (PWM_SLOW_UseStatus)
                    PWM_SLOW_STATUS_MASK = PWM_SLOW_backup.InterruptMaskValue;
                #endif /* (PWM_SLOW_UseStatus) */
                
                #if(PWM_SLOW_DeadBandMode == PWM_SLOW__B_PWM__DBM_256_CLOCKS || \
                    PWM_SLOW_DeadBandMode == PWM_SLOW__B_PWM__DBM_2_4_CLOCKS)
                    PWM_SLOW_WriteDeadTime(PWM_SLOW_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
                
                #if(PWM_SLOW_KillModeMinTime)
                    PWM_SLOW_WriteKillTime(PWM_SLOW_backup.PWMKillCounterPeriod);
                #endif /* (PWM_SLOW_KillModeMinTime) */
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            
            #if(PWM_SLOW_UseControl)
                PWM_SLOW_WriteControlRegister(PWM_SLOW_backup.PWMControlRegister); 
            #endif /* (PWM_SLOW_UseControl) */
        #endif  /* (!PWM_SLOW_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_SLOW_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_SLOW_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_SLOW_Sleep(void) 
{
    #if(PWM_SLOW_UseControl)
        if(PWM_SLOW_CTRL_ENABLE == (PWM_SLOW_CONTROL & PWM_SLOW_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_SLOW_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_SLOW_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_SLOW_UseControl) */

    /* Stop component */
    PWM_SLOW_Stop();
    
    /* Save registers configuration */
    PWM_SLOW_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_SLOW_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  PWM_SLOW_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_SLOW_Wakeup(void) 
{
     /* Restore registers values */
    PWM_SLOW_RestoreConfig();
    
    if(PWM_SLOW_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_SLOW_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
