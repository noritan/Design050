/*******************************************************************************
* File Name: RTC_INT.c
* Version 1.80
*
* Description:
*  This file contains the Interrupt Service Routine (ISR) for the RTC component.
*  This interrupt routine has entry pointes to overflow on time or date.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "RTC.h"


/*******************************************************************************
*  Place your includes, defines and code here
*******************************************************************************/
/* `#START RTC_ISR_DEFINITION` */
    #include "utils.h"
    #include "device.h"
    uint8 temp = 0u;
/* `#END` */


/*******************************************************************************
* Function Name:   RTC_EverySecondHandler
********************************************************************************
*
* Summary:
*  This function is called every second.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RTC_EverySecondHandler(void)
{
    /*  Place your every second handler code here. */
    /* `#START EVERY_SECOND_HANDLER_CODE` */
    
    /* Get and print current seconds */
    temp = RTC_ReadSecond();        
    PrintDecNumber(temp, 0u, 11u);
    
    /* Get status */
    temp = RTC_ReadStatus();
    
    /* Get and print active alarm status */
    if (RTC_STATUS_AA & temp) 
    {
        LCD_Position(1u, 15u);
        LCD_PutChar('A');
    }
    else
    {
        LCD_Position(1u, 15u);
        LCD_PutChar(' ');
    }

    /* Get and print DST status */
    if (RTC_STATUS_DST & temp) 
    {
        LCD_Position(1u, 13u);
        LCD_PutChar('D');
    }
    else
    {
        LCD_Position(1u, 13u);
        LCD_PutChar(' ');
    }
  
    /* Get and print AM/PM status */
    if (RTC_STATUS_AM_PM & temp) 
    {
        LCD_Position(0u, 14u);
        LCD_PrintString("PM");
    }
    else
    {
        LCD_Position(0u, 14u);
        LCD_PrintString("AM");
    }    

    /* Get and print leap year status */
    if (RTC_STATUS_LY & temp) 
    {
        LCD_Position(1u, 11u);
        LCD_PutChar('L');
    }
    else
    {
        LCD_Position(1u, 11u);
        LCD_PutChar(' ');                                
    }    
    /* `#END` */
}


/*******************************************************************************
* Function Name:   RTC_EveryMinuteHandler
********************************************************************************
*
* Summary:
*  This function is called every minute.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RTC_EveryMinuteHandler(void)
{
    /*  Place your every minute handler code here. */
    /* `#START EVERY_MINUTE_HANDLER_CODE` */
    
    /* Get and print current minutes */
    temp = RTC_ReadMinute();
    PrintDecNumber(temp, 0u, 8u);
    
    /* `#END` */
}


/*******************************************************************************
* Function Name:   RTC_EveryHourHandler
********************************************************************************
*
* Summary:
*  This function is called every hour.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RTC_EveryHourHandler(void)
{
    /*  Place your every hour handler code here. */
    /* `#START EVERY_HOUR_HANDLER_CODE` */
    
    /* Get and print current hours */
    temp = RTC_ReadHour();
    PrintDecNumber(temp, 0u, 5u); 
    
    /* `#END` */
}


/*******************************************************************************
* Function Name:   RTC_EveryDayHandler
********************************************************************************
*
* Summary:
*  This function is called every day.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RTC_EveryDayHandler(void)
{
    /*  Place your every day handler code here. */
    /* `#START EVERY_DAY_HANDLER_CODE` */
    
    /* Get and print current day of month */
    temp = RTC_ReadDayOfMonth();    
    PrintDecNumber(temp, 1u, 0u);
    
    /* Get and print current day of week */
    temp = RTC_CurTimeDate.DayOfWeek;
    LCD_Position(1u, 9u);
    LCD_PutChar(temp + 0x30u);
    
    /* `#END` */
}


/*******************************************************************************
* Function Name:   RTC_EveryWeekHandler
********************************************************************************
*
* Summary:
*  This function is called every week.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RTC_EveryWeekHandler(void)
{
    /*  Place your every week handler code here. */
    /* `#START EVERY_WEEK_HANDLER_CODE` */

    /* `#END` */
}


/*******************************************************************************
* Function Name:   RTC_EveryMonthHandler
********************************************************************************
*
* Summary:
*  This function is called every month.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RTC_EveryMonthHandler(void)
{
    /*  Place your every month handler code here. */
    /* `#START EVERY_MONTH_HANDLER_CODE` */
    
    /* Get and print current month */
    temp = RTC_ReadMonth();
    PrintDecNumber(temp, 1u, 3u);
    
    /* `#END` */
}


/*******************************************************************************
* Function Name:   RTC_EveryYearHandler
********************************************************************************
*
* Summary:
*  This function is called every year.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void RTC_EveryYearHandler(void)
{
    /*  Place your every year handler code here. */
    /* `#START EVERY_YEAR_HANDLER_CODE` */
    
    /* Get and print current year */
    temp = (uint8)(RTC_ReadYear() % 100u);
    PrintDecNumber(temp, 1u, 6u); 
    
    /* `#END` */
}


/*******************************************************************************
* Function Name: RTC_ISR
********************************************************************************
*
* Summary:
*  This ISR is executed on 1PPS (one pulse per second) event.
*  Global interrupt must be enabled to invoke this ISR.
*  This interrupt trigs every second.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
* RTC_currentTimeDate, RTC_dstTimeDateStart, 
*  RTC_dstTimeDateStop, RTC_dstTimeDateStart,
*  RTC_alarmCfgTimeDate, RTC_statusDateTime,
*  RTC_dstStartStatus, RTC_dstStartStatus,
*  RTC_dstStopStatus, RTC_alarmCurStatus: global
*  variables are used for the time/date, DST and alarm update procedure.
*
*  RTC_dstTimeDateStart and RTC_currentTimeDate:
*  are modified with the updated values.
*
*  RTC_statusDateTime, RTC_dstStartStatus, 
*  RTC_dstStartStatus, RTC_dstStopStatus, 
*  RTC_alarmCurStatus: global variables could be modified while
*  current time/date is updated.
*
* Side Effects:
*  Clears all interrupt status bits (react_int, limact_int, onepps_int, ctw_int,
*  and  ftw_int) in Power Manager Interrupt Status Register. If an interrupt
*  gets generated at the same time as a clear, the bit will remain set (which
*  causes another interrupt).
*
*******************************************************************************/
CY_ISR(RTC_ISR)
{
    /* Clear OPPS interrupt status flag */
    (void) CyPmReadStatus(CY_PM_ONEPPS_INT);

    /* Increment seconds counter */
    RTC_currentTimeDate.Sec++;

    /* Check if minute elapsed */
    if(RTC_currentTimeDate.Sec > RTC_MINUTE_ELAPSED)
    {
        /* Inc Min */
        RTC_currentTimeDate.Min++;

        /* Clear Sec */
        RTC_currentTimeDate.Sec = 0u;

        if(RTC_currentTimeDate.Min > RTC_HOUR_ELAPSED)
        {
            /* Inc HOUR */
            RTC_currentTimeDate.Hour++;

            /* Clear Min */
            RTC_currentTimeDate.Min = 0u;

            /* Day roll over */
            if(RTC_currentTimeDate.Hour > RTC_DAY_ELAPSED)
            {
                /* Inc DayOfMonth */
                RTC_currentTimeDate.DayOfMonth++;

                /* Clear Hour */
                RTC_currentTimeDate.Hour = 0u;

                /* Inc DayOfYear */
                RTC_currentTimeDate.DayOfYear++;

                /* Inc DayOfWeek */
                RTC_currentTimeDate.DayOfWeek++;

                /* Check DayOfWeek */
                if(RTC_currentTimeDate.DayOfWeek > RTC_WEEK_ELAPSED)
                {
                    /* start new week */
                    RTC_currentTimeDate.DayOfWeek = 1u;
                }
                
                /* Day of month roll over.
                * Check if day of month greater than 29 in February of leap year or
                * if day of month greater than 28 NOT in February of NON leap year or
                * if day of month greater than it should be in every month in non leap year
                */
                if((((0u != (RTC_statusDateTime & RTC_STATUS_LY)) && \
                    (RTC_currentTimeDate.Month == RTC_FEBRUARY)) && \
                   (RTC_currentTimeDate.DayOfMonth > \
                                    RTC_daysInMonths[RTC_currentTimeDate.Month-1] + 1)) || \
                   (((0u != (RTC_statusDateTime & RTC_STATUS_LY)) && \
                    (!(RTC_currentTimeDate.Month == RTC_FEBRUARY))) && \
                    (RTC_currentTimeDate.DayOfMonth > \
                                    RTC_daysInMonths[RTC_currentTimeDate.Month-1])) || \
                   ((!(0u != (RTC_statusDateTime & RTC_STATUS_LY))) && \
                   (RTC_currentTimeDate.DayOfMonth > \
                                    RTC_daysInMonths[RTC_currentTimeDate.Month-1])))
                {                
                    /* Inc Month */
                    RTC_currentTimeDate.Month++;

                    /* Set first day of month */
                    RTC_currentTimeDate.DayOfMonth = 1u;

                    /* Year roll over */
                    if(RTC_currentTimeDate.Month > RTC_YEAR_ELAPSED)
                    {
                        /* Inc Year */
                        RTC_currentTimeDate.Year++;

                        /* Set first month of year */
                        RTC_currentTimeDate.Month = 1u;

                        /* Set first day of year */
                        RTC_currentTimeDate.DayOfYear = 1u;

                        /* Is this year leap */
                        if(1u == RTC_LEAP_YEAR(RTC_currentTimeDate.Year))
                        {
                            /* Set leap year flag */
                            RTC_statusDateTime |= RTC_STATUS_LY;
                        }
                        else    /* not leap year */
                        {
                            /* Clear leap year */
                            RTC_statusDateTime &= ~RTC_STATUS_LY;
                        }

                        /* Alarm YEAR */
                        if(RTC_IS_BIT_SET(RTC_alarmCfgMask, RTC_ALARM_YEAR_MASK))
                        {
                            /* Years match */
                            if(RTC_alarmCfgTimeDate.Year == RTC_currentTimeDate.Year)
                            {
                                /* Rise year alarm */
                                RTC_alarmCurStatus |= RTC_ALARM_YEAR_MASK;
                            }
                            else    /* Years do not match */
                            {
                                /* Clear year alarm */
                                RTC_alarmCurStatus &= ~RTC_ALARM_YEAR_MASK;
                            }
                        } /* do not alarm year */

                        /* Set Alarm flag event */
                        RTC_SET_ALARM(RTC_alarmCfgMask,   \
                                                   RTC_alarmCurStatus, \
                                                   RTC_statusDateTime);

                        /* Every Year */
                        if(RTC_IS_BIT_SET(RTC_intervalCfgMask, \
                                                                                RTC_INTERVAL_YEAR_MASK))
                        {
                            RTC_EveryYearHandler();
                        }

                    } /* Month > 12 */

                    /* Alarm MONTH */
                    if(RTC_IS_BIT_SET(RTC_alarmCfgMask, RTC_ALARM_MONTH_MASK))
                    {
                        if(RTC_alarmCfgTimeDate.Month == RTC_currentTimeDate.Month)
                        {
                            /* Set month alarm */
                            RTC_alarmCurStatus |= RTC_ALARM_MONTH_MASK;
                        }
                        else
                        {
                            /* Clear month alarm */
                            RTC_alarmCurStatus &= ~RTC_ALARM_MONTH_MASK;
                        }
                    }   /* Month alarm is masked */

                    #if(1u == RTC_DST_FUNC_ENABLE)
                        if(RTC_dstTimeDateStop.Month == RTC_currentTimeDate.Month)
                        {
                            RTC_dstStopStatus |= RTC_DST_MONTH;
                        }
                        else
                        {
                            RTC_dstStopStatus &= ~RTC_DST_MONTH;
                        }

                        if(RTC_dstTimeDateStart.Month == RTC_currentTimeDate.Month)
                        {
                            RTC_dstStartStatus |= RTC_DST_MONTH;
                        }
                        else
                        {
                            RTC_dstStartStatus &= ~RTC_DST_MONTH;
                        }
                    #endif /* 1u == RTC_DST_FUNC_ENABLE */

                    /* Set Alarm flag event */
                    RTC_SET_ALARM(RTC_alarmCfgMask,   \
                                               RTC_alarmCurStatus, \
                                               RTC_statusDateTime);
                               
                    /* Every Month */
                    if(RTC_IS_BIT_SET(RTC_intervalCfgMask, \
                                                   RTC_INTERVAL_MONTH_MASK))
                    {
                        RTC_EveryMonthHandler();
                    }
                }   /* Day roll over */

                /* Alarm DAYOFWEEK */
                if(RTC_IS_BIT_SET(RTC_alarmCfgMask, RTC_ALARM_DAYOFWEEK_MASK))
                {
                    if(RTC_alarmCfgTimeDate.DayOfWeek == RTC_currentTimeDate.DayOfWeek)
                    {
                        /* Set day of week alarm */
                        RTC_alarmCurStatus |= RTC_ALARM_DAYOFWEEK_MASK;
                    }
                    else
                    {
                        /* Clear day of week alarm */
                        RTC_alarmCurStatus &= ~RTC_ALARM_DAYOFWEEK_MASK;
                    }
                }   /* Day of week alarm is masked */

                /* Alarm DAYOFYEAR */
                if(RTC_IS_BIT_SET(RTC_alarmCfgMask, RTC_ALARM_DAYOFYEAR_MASK))
                {
                    if(RTC_alarmCfgTimeDate.DayOfYear == RTC_currentTimeDate.DayOfYear)
                    {
                        /* Set day of year alarm */
                        RTC_alarmCurStatus |= RTC_ALARM_DAYOFYEAR_MASK;
                    }
                    else
                    {
                        /* Clear day of year alarm */
                        RTC_alarmCurStatus &= ~RTC_ALARM_DAYOFYEAR_MASK;
                    }
                }   /* Day of year alarm is masked */

                /* Alarm DAYOFMONTH */
                if(RTC_IS_BIT_SET(RTC_alarmCfgMask, RTC_ALARM_DAYOFMONTH_MASK))
                {
                    if(RTC_alarmCfgTimeDate.DayOfMonth == RTC_currentTimeDate.DayOfMonth)
                    {
                        /* Set day of month alarm */
                        RTC_alarmCurStatus |= RTC_ALARM_DAYOFMONTH_MASK;
                    }
                       else
                    {
                        /* Clear day of month alarm */
                        RTC_alarmCurStatus &= ~RTC_ALARM_DAYOFMONTH_MASK;
                    }
                }   /* Day of month alarm is masked */

                #if(1u == RTC_DST_FUNC_ENABLE)
                    if (RTC_dstTimeDateStop.DayOfMonth == RTC_currentTimeDate.DayOfMonth)
                    {
                        RTC_dstStopStatus |= RTC_DST_DAYOFMONTH;
                    }
                    else
                    {
                        RTC_dstStopStatus &= ~RTC_DST_DAYOFMONTH;
                    }

                    if(RTC_dstTimeDateStart.DayOfMonth == RTC_currentTimeDate.DayOfMonth)
                    {
                        RTC_dstStartStatus |= RTC_DST_DAYOFMONTH;
                    }
                    else
                    {
                        RTC_dstStartStatus &= ~RTC_DST_DAYOFMONTH;
                    }
                #endif /* 1u == RTC_DST_FUNC_ENABLE */

                /* Set Alarm flag event */
                RTC_SET_ALARM(RTC_alarmCfgMask,   \
                                           RTC_alarmCurStatus, \
                                           RTC_statusDateTime);
                           
                /* Every Day */
                if(RTC_IS_BIT_SET(RTC_intervalCfgMask, RTC_INTERVAL_DAY_MASK))
                {
                    RTC_EveryDayHandler();
                }

                if(1u == RTC_currentTimeDate.DayOfWeek)
                {
                    /* Every Week */
                    if(RTC_IS_BIT_SET(RTC_intervalCfgMask, \
                                                                                RTC_INTERVAL_WEEK_MASK))
                    {
                       RTC_EveryWeekHandler();
                    }
                }

            } /* End of day roll over */

            /* Status set PM/AM flag */
            if(RTC_currentTimeDate.Hour < RTC_HALF_OF_DAY_ELAPSED)
            {
                /* AM Hour 00:00-11:59, flag zero */
                RTC_statusDateTime &= ~RTC_STATUS_AM_PM;
            }
            else
            {
                /* PM Hour 12:00-23:59, flag set */
                RTC_statusDateTime |= RTC_STATUS_AM_PM;
            }

            #if(1u == RTC_DST_FUNC_ENABLE)
                if(RTC_dstTimeDateStop.Hour == RTC_currentTimeDate.Hour)
                {
                    RTC_dstStopStatus |= RTC_DST_HOUR;
                }
                else
                {
                    RTC_dstStopStatus &= ~RTC_DST_HOUR;
                }

                if(RTC_dstTimeDateStart.Hour == RTC_currentTimeDate.Hour)
                {
                    RTC_dstStartStatus |= RTC_DST_HOUR;
                }
                else
                {
                RTC_dstStartStatus &= ~RTC_DST_HOUR;
                }

                /* DST Enable ? */
                if(RTC_IS_BIT_SET(RTC_dstModeType, RTC_DST_ENABLE))
                {
                    if(RTC_IS_BIT_SET(RTC_statusDateTime, RTC_STATUS_DST))
                    {
                        if(RTC_IS_BIT_SET(RTC_dstStopStatus, RTC_DST_HOUR    | \
                                                                                    RTC_DST_DAYOFMONTH | \
                                                                                    RTC_DST_MONTH))
                        {
                            /* Substruct from current value of minutes, number of minutes
                            * in DST offset which is out of complete hour
                            */
                            RTC_currentTimeDate.Min -= \
                                                RTC_dstOffsetMin % (RTC_HOUR_ELAPSED + 1u);

                            /* Is minute value negative? */
                            if(RTC_currentTimeDate.Min > RTC_HOUR_ELAPSED)
                            {
                                /* Convert to the positive. 
                                * HOUR_ELAPSED -     (~currentTimeDate.Min    ) == 
                                * HOUR_ELAPSED + 1 - (~currentTimeDate.Min + 1)
                                */
                                RTC_currentTimeDate.Min = \
                                                RTC_HOUR_ELAPSED - (~RTC_currentTimeDate.Min);

                                RTC_currentTimeDate.Hour--;
                            }

                            RTC_currentTimeDate.Hour -= \
                                                RTC_dstOffsetMin / (RTC_HOUR_ELAPSED + 1u);

                            /* Day roll over
                            * Is hour value negative? */
                            if(RTC_currentTimeDate.Hour > RTC_DAY_ELAPSED)
                            {
                                /* Convert to the positive. 
                                * DAY_ELAPSED - (~currentTimeDate.Hour) == 
                                * DAY_ELAPSED + 1 - (~currentTimeDate.Hour + 1)
                                */
                                RTC_currentTimeDate.Hour = \
                                                RTC_DAY_ELAPSED - (~RTC_currentTimeDate.Hour);

                                /* Status set PM/AM flag */
                                if(RTC_currentTimeDate.Hour < RTC_HALF_OF_DAY_ELAPSED)
                                {
                                    /* AM Hour 00:00-11:59, flag zero */
                                    RTC_statusDateTime &= ~RTC_STATUS_AM_PM;
                                }
                                else
                                {
                                    /* PM Hour 12:00-23:59, flag set */
                                    RTC_statusDateTime |= RTC_STATUS_AM_PM;
                                }

                                RTC_currentTimeDate.DayOfMonth--;
                                RTC_currentTimeDate.DayOfYear--;
                                RTC_currentTimeDate.DayOfWeek--;

                                if(0u == RTC_currentTimeDate.DayOfWeek)
                                {
                                    RTC_currentTimeDate.DayOfWeek = RTC_DAYS_IN_WEEK;
                                }

                                if(0u == RTC_currentTimeDate.DayOfMonth)
                                {
                                    RTC_currentTimeDate.Month--;
                                    if(0u == RTC_currentTimeDate.Month)
                                    {
                                        RTC_currentTimeDate.Month = RTC_DECEMBER;

                                        RTC_currentTimeDate.DayOfMonth = \
                                            RTC_daysInMonths[RTC_currentTimeDate.Month - 1u];

                                        RTC_currentTimeDate.Year--;

                                        if(1u == RTC_LEAP_YEAR(RTC_currentTimeDate.Year))
                                        {
                                            /* LP - true, else - false */
                                            RTC_statusDateTime |= RTC_STATUS_LY;
                                            RTC_currentTimeDate.DayOfYear = \
                                                                                    RTC_DAYS_IN_LEAP_YEAR;
                                        }
                                        else
                                        {
                                            RTC_statusDateTime &= ~RTC_STATUS_LY;
                                            RTC_currentTimeDate.DayOfYear = RTC_DAYS_IN_YEAR;
                                        }
                                        RTC_EveryYearHandler();
                                    }
                                    else
                                    {
                                        RTC_currentTimeDate.DayOfMonth = \
                                            RTC_daysInMonths[RTC_currentTimeDate.Month - 1u];
                                    }
                                    RTC_EveryMonthHandler();
                                }
                                RTC_EveryDayHandler();
                            }
                            RTC_statusDateTime &= ~RTC_STATUS_DST;
                            RTC_dstStopStatus = 0u;
                        }
                    }
                    else
                    {
                        if(RTC_IS_BIT_SET(RTC_dstStartStatus, \
                                                      (RTC_DST_HOUR | RTC_DST_DAYOFMONTH | \
                                                       RTC_DST_MONTH)))
                        {
                            /* Add Hour and Min */
                            RTC_currentTimeDate.Min += \
                                                RTC_dstOffsetMin % (RTC_HOUR_ELAPSED + 1u);

                            if(RTC_currentTimeDate.Min > RTC_HOUR_ELAPSED)
                            {
                                /* Adjust Min */
                                RTC_currentTimeDate.Min -= (RTC_HOUR_ELAPSED + 1u);
                                RTC_currentTimeDate.Hour++;
                            }

                            RTC_currentTimeDate.Hour += \
                                                RTC_dstOffsetMin / (RTC_HOUR_ELAPSED + 1u);

                            if(RTC_currentTimeDate.Hour > RTC_DAY_ELAPSED)
                            {
                                /* Adjust hour, add day */
                                RTC_currentTimeDate.Hour -= (RTC_DAY_ELAPSED + 1u);

                                /* Status set PM/AM flag */
                                if(RTC_currentTimeDate.Hour < RTC_HALF_OF_DAY_ELAPSED)
                                {
                                    /* AM Hour 00:00-11:59, flag zero */
                                    RTC_statusDateTime &= ~RTC_STATUS_AM_PM;
                                }
                                else
                                {
                                    /* PM Hour 12:00-23:59, flag set */
                                    RTC_statusDateTime |= RTC_STATUS_AM_PM;
                                }

                                RTC_currentTimeDate.DayOfMonth++;
                                RTC_currentTimeDate.DayOfYear++;
                                RTC_currentTimeDate.DayOfWeek++;

                                if(RTC_currentTimeDate.DayOfWeek > RTC_WEEK_ELAPSED)
                                {
                                    RTC_currentTimeDate.DayOfWeek = 1u;
                                }

                                if(RTC_currentTimeDate.DayOfMonth > \
                                            RTC_daysInMonths[RTC_currentTimeDate.Month - 1u])
                                {
                                    RTC_currentTimeDate.Month++;
                                    RTC_currentTimeDate.DayOfMonth = 1u;
                                    if(RTC_currentTimeDate.Month > RTC_YEAR_ELAPSED)
                                    {
                                        RTC_currentTimeDate.Month = RTC_JANUARY;
                                        RTC_currentTimeDate.Year++;
                                        
                                        if(1u == RTC_LEAP_YEAR(RTC_currentTimeDate.Year))
                                        {
                                            /* LP - true, else - false */
                                            RTC_statusDateTime |= RTC_STATUS_LY;
                                        }
                                        else
                                        {
                                            RTC_statusDateTime &= ~RTC_STATUS_LY;
                                        }
                                        RTC_currentTimeDate.DayOfYear = 1u;

                                        RTC_EveryYearHandler();
                                    }
                                    RTC_EveryMonthHandler();
                                }
                                RTC_EveryDayHandler();
                            }
                            RTC_statusDateTime |= RTC_STATUS_DST;
                            RTC_dstStartStatus = 0u;

                            /* Month */
                            if(RTC_dstTimeDateStop.Month == RTC_currentTimeDate.Month)
                            {
                                RTC_dstStopStatus |= RTC_DST_MONTH;
                            }
                            else
                            {
                                RTC_dstStopStatus &= ~RTC_DST_MONTH;
                            }

                            /* DayOfMonth */
                            if(RTC_dstTimeDateStop.DayOfMonth == \
                                                                            RTC_currentTimeDate.DayOfMonth)
                            {
                                RTC_dstStopStatus |= RTC_DST_DAYOFMONTH;
                            }
                            else
                            {
                                RTC_dstStopStatus &= ~RTC_DST_DAYOFMONTH;
                            }
                        }
                    }

                    /* Alarm DAYOFWEEK */
                    if(RTC_IS_BIT_SET(RTC_alarmCfgMask,RTC_ALARM_DAYOFWEEK_MASK))
                    {
                        if(RTC_alarmCfgTimeDate.DayOfWeek == RTC_currentTimeDate.DayOfWeek)
                        {
                            RTC_alarmCurStatus |= RTC_ALARM_DAYOFWEEK_MASK;
                        }
                        else
                        {
                            RTC_alarmCurStatus &= ~RTC_ALARM_DAYOFWEEK_MASK;
                        }
                    }

                    /* Alarm DAYOFYEAR */
                    if(RTC_IS_BIT_SET(RTC_alarmCfgMask,RTC_ALARM_DAYOFYEAR_MASK))
                    {
                        if(RTC_alarmCfgTimeDate.DayOfYear == RTC_currentTimeDate.DayOfYear)
                        {
                            RTC_alarmCurStatus |= RTC_ALARM_DAYOFYEAR_MASK;
                        }
                        else
                        {
                            RTC_alarmCurStatus &= ~RTC_ALARM_DAYOFYEAR_MASK;
                        }
                    }

                    /* Alarm DAYOFMONTH */
                    if(RTC_IS_BIT_SET(RTC_alarmCfgMask, \
                                                   RTC_ALARM_DAYOFMONTH_MASK))
                    {
                        if(RTC_alarmCfgTimeDate.DayOfMonth == RTC_currentTimeDate.DayOfMonth)
                        {
                            RTC_alarmCurStatus |= RTC_ALARM_DAYOFMONTH_MASK;
                        }
                        else
                        {
                            RTC_alarmCurStatus &= ~RTC_ALARM_DAYOFMONTH_MASK;
                        }
                    }

                    /* Alarm MONTH */
                    if(RTC_IS_BIT_SET(RTC_alarmCfgMask,RTC_ALARM_MONTH_MASK))
                    {
                        if(RTC_alarmCfgTimeDate.Month == RTC_currentTimeDate.Month)
                        {
                            RTC_alarmCurStatus |= RTC_ALARM_MONTH_MASK;
                        }
                        else
                        {
                            RTC_alarmCurStatus &= ~RTC_ALARM_MONTH_MASK;
                        }
                    }

                    /* Alarm YEAR */
                    if(RTC_IS_BIT_SET(RTC_alarmCfgMask, RTC_ALARM_YEAR_MASK))
                    {
                        if(RTC_alarmCfgTimeDate.Year == RTC_currentTimeDate.Year)
                        {
                            RTC_alarmCurStatus |= RTC_ALARM_YEAR_MASK;
                        }
                        else
                        {
                            RTC_alarmCurStatus &= ~RTC_ALARM_YEAR_MASK;
                        }
                    }
                    
                    /* Set Alarm flag event */
                    RTC_SET_ALARM(RTC_alarmCfgMask,   \
                                               RTC_alarmCurStatus, \
                                               RTC_statusDateTime);
                }
            #endif /* 1u == RTC_DST_FUNC_ENABLE */

            /* Alarm HOUR */
            if(RTC_IS_BIT_SET(RTC_alarmCfgMask ,RTC_ALARM_HOUR_MASK))
            {
                if(RTC_alarmCfgTimeDate.Hour == RTC_currentTimeDate.Hour)
                {
                    RTC_alarmCurStatus |= RTC_ALARM_HOUR_MASK;
                }
                else
                {
                    RTC_alarmCurStatus &= ~RTC_ALARM_HOUR_MASK;
                }
            }
            
            /* Set Alarm flag event */
            RTC_SET_ALARM(RTC_alarmCfgMask,   \
                                       RTC_alarmCurStatus, \
                                       RTC_statusDateTime);
            
            /* Every Hour */
            if(RTC_IS_BIT_SET(RTC_intervalCfgMask,RTC_INTERVAL_HOUR_MASK))
            {
                RTC_EveryHourHandler();
            }
        } /* Min > 59 = Hour */

        /* Alarm MIN */
        if(RTC_IS_BIT_SET(RTC_alarmCfgMask, RTC_ALARM_MIN_MASK))
        {
            if(RTC_alarmCfgTimeDate.Min == RTC_currentTimeDate.Min)
            {
                RTC_alarmCurStatus |= RTC_ALARM_MIN_MASK;
            }
            else
            {
                RTC_alarmCurStatus &= ~RTC_ALARM_MIN_MASK;
            }
        }

        /* Set Alarm flag event */
        RTC_SET_ALARM(RTC_alarmCfgMask,   \
                                   RTC_alarmCurStatus, \
                                   RTC_statusDateTime);
        
        /* Every Min */
        if(RTC_IS_BIT_SET(RTC_intervalCfgMask, RTC_INTERVAL_MIN_MASK))
        {
            RTC_EveryMinuteHandler();
        }
    } /* Sec */

    /* Alarm SEC */
    if(RTC_IS_BIT_SET(RTC_alarmCfgMask, RTC_ALARM_SEC_MASK))
    {
        if(RTC_alarmCfgTimeDate.Sec == RTC_currentTimeDate.Sec)
        {
            RTC_alarmCurStatus |= RTC_ALARM_SEC_MASK;
        }
        else
        {
            RTC_alarmCurStatus &= ~RTC_ALARM_SEC_MASK;
        }
    }

    /* Set Alarm flag event */
    RTC_SET_ALARM(RTC_alarmCfgMask,   \
                               RTC_alarmCurStatus, \
                               RTC_statusDateTime);
   
    /* Execute every second handler if needed */
    if(RTC_IS_BIT_SET(RTC_intervalCfgMask,RTC_INTERVAL_SEC_MASK))
    {
        RTC_EverySecondHandler();
    }

}


/* [] END OF FILE */
