/*******************************************************************************
* File Name: main.c
*
* Version: 3.10
*
* Description:
*  This is source code for the datasheet example of the Real Time Clock (RTC)
*  component.
*
*  The PrintDecNumber() function is implemented in the utils.c file. It displays
*  decimal numbers (first parameter) on a specific row (second parameter) and
*  column (the third parameter) on the Character LCD component, named LCD. If
*  the Character LCD component's name is changed it also should be updated in
*  this function.
*
*  There are interrupt stubs in the RTC ISR. The every second interrupt for this
*  example project is listed below. The active alarm, DST, AM/PM and leap year
*  statuses renew code is removed from the listing below, as it is the same as
*  in the main() function and are described above. The only second value update
*  code is shown below.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>
#include "utils.h"


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Main function performs following functions:
*   1. Declares date and time structure and fill it with the initial values
*   2. Enables global interrupts
*   3. Sets initial time and date values
*   4. Sets alarm date, time and mask
*   5. Sets interval mask
*   6. Sets DST start and stop configuration
*   7. Prints current date and time values.
*   8. Afterwards, device is continuosly switched to the Sleep low power mode.
*      When the 1PPS event occurs device wakes up, ISR is executed and device
*      is switched to the Sleep mode again till the next 1PPS event. This
*      applies only to PSoC 3 device.
*      For more information refer to the device TRM and System
*      Reference Guide.
*
*   The information on the display is updated in the ISR.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void main()
{
    uint8 tmpVar = 0u;

    RTC_TIME_DATE Start;

    /* Fill struct with date and time */
    Start.Sec = 55u;
    Start.Min = 59u;
    Start.Hour = 22u;
    Start.DayOfMonth = 31u;
    Start.Month = 12u;
    Start.Year = 2007u;

    /* Enable all interrupts */
    CyGlobalIntEnable;

    /* Set date and time */
    RTC_WriteTime(&Start);

    /* Set alarm date and time */
    RTC_WriteAlarmSecond(5u);
    RTC_WriteAlarmMinute(3u);
    RTC_WriteAlarmHour(1u);
    RTC_WriteAlarmDayOfMonth(1u);
    RTC_WriteAlarmMonth(1u);
    RTC_WriteAlarmYear(2008u);

    /* Set alarm mask */
    RTC_WriteAlarmMask(RTC_ALARM_SEC_MASK   | RTC_ALARM_MIN_MASK        |
                       RTC_ALARM_HOUR_MASK  | RTC_ALARM_DAYOFMONTH_MASK |
                       RTC_ALARM_MONTH_MASK | RTC_ALARM_YEAR_MASK);

    /* Set interval mask - handling of interrupt stubs of the RTC component */
    RTC_WriteIntervalMask(RTC_INTERVAL_SEC_MASK  | RTC_INTERVAL_MIN_MASK   |
                          RTC_INTERVAL_HOUR_MASK | RTC_INTERVAL_DAY_MASK   |
                          RTC_INTERVAL_WEEK_MASK | RTC_INTERVAL_MONTH_MASK |
                          RTC_INTERVAL_YEAR_MASK);

    /* DST start configuration */
    RTC_WriteDSTMode(RTC_DST_ENABLE | RTC_DST_FIXDATE);
    RTC_WriteDSTStartHour(23u);
    RTC_WriteDSTStartDayOfMonth(31u);
    RTC_WriteDSTStartMonth(12u);

    /* DST stop configuration */
    RTC_WriteDSTStopHour(2u);
    RTC_WriteDSTStopDayOfMonth(1u);
    RTC_WriteDSTStopMonth(1u);
    RTC_WriteDSTOffset(123u);

    /* Start RTC */
    RTC_Start();

    /* Start LCD */
    LCD_Start();

    /* Prepare 0th column */
    LCD_Position(0u, 0u);
    LCD_PrintString("RTC    :  :  ");

    /* Print current time */
    tmpVar = RTC_ReadSecond();
    PrintDecNumber(tmpVar, 0u, 11u);
    tmpVar = RTC_ReadMinute();
    PrintDecNumber(tmpVar, 0u, 8u);
    tmpVar = RTC_ReadHour();
    PrintDecNumber(tmpVar, 0u, 5u);

    /* Prepare 1st column */
    LCD_Position(1u, 0u);
    LCD_PrintString("  -  - ");

    /* Get and print day of month */
    tmpVar = RTC_ReadDayOfMonth();
    PrintDecNumber(tmpVar, 1u, 0u);

    /* Get and print month */
    tmpVar = RTC_ReadMonth();
    PrintDecNumber(tmpVar, 1u, 3u);

    /* Get and print year */
    tmpVar = (uint8)(RTC_ReadYear() % 100u);
    PrintDecNumber(tmpVar, 1u, 6u);

    /* Get and print day of week */
    tmpVar = RTC_currentTimeDate.DayOfWeek;
    LCD_Position(1u, 9u);
    LCD_PutChar(tmpVar + 0x30u);

    /* Get status */
    tmpVar = RTC_ReadStatus();

    /* Get and print if year is leap */
    if(RTC_STATUS_LY & tmpVar)
    {
        LCD_Position(1u, 11u);
        LCD_PutChar('L');
    }
    else
    {
        LCD_Position(1u, 11u);
        LCD_PutChar(' ');
    }

    /* Get and print daytime AM/PM */
    if(RTC_STATUS_AM_PM & tmpVar)
    {
        LCD_Position(0u, 14u);
        LCD_PrintString("PM");
    }
    else
    {
        LCD_Position(0u, 14u);
        LCD_PrintString("AM");
    }

    /* Get and print DST status */
    if (RTC_STATUS_DST & tmpVar)
    {
        LCD_Position(1u, 13u);
        LCD_PutChar('D');
    }
    else
    {
        LCD_Position(1u, 13u);
        LCD_PutChar(' ');
    }

    /* Get and print alarm status */
    if (RTC_STATUS_AA & tmpVar)
    {
        LCD_Position(1u, 15u);
        LCD_PutChar('A');
    }
    else
    {
        LCD_Position(1u, 15u);
        LCD_PutChar(' ');
    }

    while(1u)
    {
        /* Make a 100 ms delay */
        CyDelay(100);

        #if(CY_PSOC3 || CY_PSOC5LP)

            /* Prepare clock tree configuration for low power mode entry */
            CyPmSaveClocks();

            #if(CY_PSOC3)
                /*******************************************************************
                * Disable RTC interrupt before entering Sleep mode. The device will
                * wake up on one pulse-per-second event, but the ISR will be
                * executed when RTC interrupts will be enabled, after the clocks
                * configuration will be restores. Potentially, this will allow to
                * execute RTC ISR quicker, as CyPmSaveClocks() function could
                * decrease master clock frequency. For PSoC 5 architectures
                * (both PSoC 5 and PSoC 5LP devices), an interrupt is required for
                * the CPU to wake up, so interrupt is disabled for PSoC3 only.
                *******************************************************************/
                RTC_DisableInt();
            #endif /* (CY_PSOC3) */

            /* Entry Sleep low power mode */
            CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_ONE_PPS);

            /* Restore clock tree configuration */
            CyPmRestoreClocks();


            #if(CY_PSOC3)
                /*******************************************************************
                * Enable RTC interrupt for ISR to be executed on restored clock
                * frequency.
                *******************************************************************/
                RTC_EnableInt();
            #endif /* (CY_PSOC3) */

        #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    }
}


/* [] END OF FILE */
