/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <device.h>

void main()
{
    RTC_1_Start();
    PWM_SLOW_Start();
    PWM_FAST_Start();
    CyXTAL_32KHZ_SetPowerMode(1);

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        CyDelay(5000);
//        PWM_FAST_Sleep();
//        PWM_SLOW_Sleep();
//        SW2_P6_1_ClearInterrupt();
//        CyPmSaveClocks();
//        CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_PICU);
//        CyPmRestoreClocks();
//        PWM_SLOW_Wakeup();
//        PWM_FAST_Wakeup();
        SW2_P6_1_ClearInterrupt();
        CyPmSaveClocks();
        CyPmAltAct(PM_ALT_ACT_TIME_NONE, PM_ALT_ACT_SRC_PICU);
        CyPmRestoreClocks();
    }
}

/* [] END OF FILE */
