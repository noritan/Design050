/*******************************************************************************
* File Name: PWM_FAST_PM.c
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
#include "PWM_FAST.h"

static PWM_FAST_backupStruct PWM_FAST_backup;


/*******************************************************************************
* Function Name: PWM_FAST_SaveConfig
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
*  PWM_FAST_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void PWM_FAST_SaveConfig(void) 
{
    
    #if(!PWM_FAST_UsingFixedFunction)
        #if (CY_PSOC5A)
            PWM_FAST_backup.PWMUdb = PWM_FAST_ReadCounter();
            PWM_FAST_backup.PWMPeriod = PWM_FAST_ReadPeriod();
            #if (PWM_FAST_UseStatus)
                PWM_FAST_backup.InterruptMaskValue = PWM_FAST_STATUS_MASK;
            #endif /* (PWM_FAST_UseStatus) */
            
            #if(PWM_FAST_UseOneCompareMode)
                PWM_FAST_backup.PWMCompareValue = PWM_FAST_ReadCompare();
            #else
                PWM_FAST_backup.PWMCompareValue1 = PWM_FAST_ReadCompare1();
                PWM_FAST_backup.PWMCompareValue2 = PWM_FAST_ReadCompare2();
            #endif /* (PWM_FAST_UseOneCompareMode) */
            
           #if(PWM_FAST_DeadBandUsed)
                PWM_FAST_backup.PWMdeadBandValue = PWM_FAST_ReadDeadTime();
            #endif /* (PWM_FAST_DeadBandUsed) */
          
            #if ( PWM_FAST_KillModeMinTime)
                PWM_FAST_backup.PWMKillCounterPeriod = PWM_FAST_ReadKillTime();
            #endif /* ( PWM_FAST_KillModeMinTime) */
        #endif /* (CY_PSOC5A) */
        
        #if (CY_PSOC3 || CY_PSOC5LP)
            #if(!PWM_FAST_PWMModeIsCenterAligned)
                PWM_FAST_backup.PWMPeriod = PWM_FAST_ReadPeriod();
            #endif /* (!PWM_FAST_PWMModeIsCenterAligned) */
            PWM_FAST_backup.PWMUdb = PWM_FAST_ReadCounter();
            #if (PWM_FAST_UseStatus)
                PWM_FAST_backup.InterruptMaskValue = PWM_FAST_STATUS_MASK;
            #endif /* (PWM_FAST_UseStatus) */
            
            #if(PWM_FAST_DeadBandMode == PWM_FAST__B_PWM__DBM_256_CLOCKS || \
                PWM_FAST_DeadBandMode == PWM_FAST__B_PWM__DBM_2_4_CLOCKS)
                PWM_FAST_backup.PWMdeadBandValue = PWM_FAST_ReadDeadTime();
            #endif /*  deadband count is either 2-4 clocks or 256 clocks */
            
            #if(PWM_FAST_KillModeMinTime)
                 PWM_FAST_backup.PWMKillCounterPeriod = PWM_FAST_ReadKillTime();
            #endif /* (PWM_FAST_KillModeMinTime) */
        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
        
        #if(PWM_FAST_UseControl)
            PWM_FAST_backup.PWMControlRegister = PWM_FAST_ReadControlRegister();
        #endif /* (PWM_FAST_UseControl) */
    #endif  /* (!PWM_FAST_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_FAST_RestoreConfig
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
*  PWM_FAST_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_FAST_RestoreConfig(void) 
{
        #if(!PWM_FAST_UsingFixedFunction)
            #if (CY_PSOC5A)
                /* Interrupt State Backup for Critical Region*/
                uint8 PWM_FAST_interruptState;
                /* Enter Critical Region*/
                PWM_FAST_interruptState = CyEnterCriticalSection();
                #if (PWM_FAST_UseStatus)
                    /* Use the interrupt output of the status register for IRQ output */
                    PWM_FAST_STATUS_AUX_CTRL |= PWM_FAST_STATUS_ACTL_INT_EN_MASK;
                    
                    PWM_FAST_STATUS_MASK = PWM_FAST_backup.InterruptMaskValue;
                #endif /* (PWM_FAST_UseStatus) */
                
                #if (PWM_FAST_Resolution == 8)
                    /* Set FIFO 0 to 1 byte register for period*/
                    PWM_FAST_AUX_CONTROLDP0 |= (PWM_FAST_AUX_CTRL_FIFO0_CLR);
                #else /* (PWM_FAST_Resolution == 16)*/
                    /* Set FIFO 0 to 1 byte register for period */
                    PWM_FAST_AUX_CONTROLDP0 |= (PWM_FAST_AUX_CTRL_FIFO0_CLR);
                    PWM_FAST_AUX_CONTROLDP1 |= (PWM_FAST_AUX_CTRL_FIFO0_CLR);
                #endif /* (PWM_FAST_Resolution == 8) */
                /* Exit Critical Region*/
                CyExitCriticalSection(PWM_FAST_interruptState);
                
                PWM_FAST_WriteCounter(PWM_FAST_backup.PWMUdb);
                PWM_FAST_WritePeriod(PWM_FAST_backup.PWMPeriod);
                
                #if(PWM_FAST_UseOneCompareMode)
                    PWM_FAST_WriteCompare(PWM_FAST_backup.PWMCompareValue);
                #else
                    PWM_FAST_WriteCompare1(PWM_FAST_backup.PWMCompareValue1);
                    PWM_FAST_WriteCompare2(PWM_FAST_backup.PWMCompareValue2);
                #endif /* (PWM_FAST_UseOneCompareMode) */
                
               #if(PWM_FAST_DeadBandMode == PWM_FAST__B_PWM__DBM_256_CLOCKS || \
                   PWM_FAST_DeadBandMode == PWM_FAST__B_PWM__DBM_2_4_CLOCKS)
                    PWM_FAST_WriteDeadTime(PWM_FAST_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
                #if ( PWM_FAST_KillModeMinTime)
                    PWM_FAST_WriteKillTime(PWM_FAST_backup.PWMKillCounterPeriod);
                #endif /* ( PWM_FAST_KillModeMinTime) */
            #endif /* (CY_PSOC5A) */
            
            #if (CY_PSOC3 || CY_PSOC5LP)
                #if(!PWM_FAST_PWMModeIsCenterAligned)
                    PWM_FAST_WritePeriod(PWM_FAST_backup.PWMPeriod);
                #endif /* (!PWM_FAST_PWMModeIsCenterAligned) */
                PWM_FAST_WriteCounter(PWM_FAST_backup.PWMUdb);
                #if (PWM_FAST_UseStatus)
                    PWM_FAST_STATUS_MASK = PWM_FAST_backup.InterruptMaskValue;
                #endif /* (PWM_FAST_UseStatus) */
                
                #if(PWM_FAST_DeadBandMode == PWM_FAST__B_PWM__DBM_256_CLOCKS || \
                    PWM_FAST_DeadBandMode == PWM_FAST__B_PWM__DBM_2_4_CLOCKS)
                    PWM_FAST_WriteDeadTime(PWM_FAST_backup.PWMdeadBandValue);
                #endif /* deadband count is either 2-4 clocks or 256 clocks */
                
                #if(PWM_FAST_KillModeMinTime)
                    PWM_FAST_WriteKillTime(PWM_FAST_backup.PWMKillCounterPeriod);
                #endif /* (PWM_FAST_KillModeMinTime) */
            #endif /* (CY_PSOC3 || CY_PSOC5LP) */
            
            #if(PWM_FAST_UseControl)
                PWM_FAST_WriteControlRegister(PWM_FAST_backup.PWMControlRegister); 
            #endif /* (PWM_FAST_UseControl) */
        #endif  /* (!PWM_FAST_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_FAST_Sleep
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
*  PWM_FAST_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_FAST_Sleep(void) 
{
    #if(PWM_FAST_UseControl)
        if(PWM_FAST_CTRL_ENABLE == (PWM_FAST_CONTROL & PWM_FAST_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_FAST_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_FAST_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_FAST_UseControl) */

    /* Stop component */
    PWM_FAST_Stop();
    
    /* Save registers configuration */
    PWM_FAST_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_FAST_Wakeup
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
*  PWM_FAST_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_FAST_Wakeup(void) 
{
     /* Restore registers values */
    PWM_FAST_RestoreConfig();
    
    if(PWM_FAST_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_FAST_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
