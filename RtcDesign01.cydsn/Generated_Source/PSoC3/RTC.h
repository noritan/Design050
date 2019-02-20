/*******************************************************************************
* File Name: RTC.h
* Version 1.80
*
* Description:
*  This file provides constants and parameter values for the RTC Component.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_RTC_RTC_H)
#define CY_RTC_RTC_H

#include "cytypes.h"
#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cyPm.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component RTC_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*   Conditional Compilation Parameters
***************************************/

/* what day of the week is start of week */
#define RTC_START_OF_WEEK          (1u)

/* Daylight saving time */
#define RTC_DST_FUNC_ENABLE        (1u)


/***************************************
*    Data Struct Definitions
***************************************/

typedef struct _RTC_TIME_DATE
{
    uint8 Sec;
    uint8 Min;
    uint8 Hour;
    uint8 DayOfWeek;
    uint8 DayOfMonth;
    uint16 DayOfYear;
    uint8 Month;
    uint16 Year;
} volatile RTC_TIME_DATE;

typedef struct _RTC_DSTIME
{
    uint8 Hour;
    uint8 DayOfWeek;
    uint8 Week;
    uint8 DayOfMonth;
    uint8 Month;
} volatile RTC_DSTIME;


/***************************************
*    Function Prototypes
***************************************/

CY_ISR_PROTO(RTC_ISR);

void RTC_Start(void) ;
void RTC_Stop(void) ;
void RTC_EnableInt(void) ;
void RTC_DisableInt(void) ;
void  RTC_Init(void) ;
void RTC_Enable(void) ;

RTC_TIME_DATE* RTC_ReadTime(void) ;
void RTC_WriteTime(RTC_TIME_DATE *timeDate) ;

/* RTC write functions to set Start Values */
void RTC_WriteSecond(uint8 second) ;
void RTC_WriteMinute(uint8 minute) ;
void RTC_WriteHour(uint8 hour) ;
void RTC_WriteDayOfMonth(uint8 dayOfMonth) ;
void RTC_WriteMonth(uint8 month) ;
void RTC_WriteYear(uint16 year) ;

/* RTC Alarm write settings */
void RTC_WriteAlarmSecond(uint8 second) ;
void RTC_WriteAlarmMinute(uint8 minute) ;
void RTC_WriteAlarmHour(uint8 hour) ;
void RTC_WriteAlarmDayOfMonth(uint8 dayOfMonth) ;
void RTC_WriteAlarmMonth(uint8 month) ;
void RTC_WriteAlarmYear(uint16 year) ;
void RTC_WriteAlarmDayOfWeek(uint8 dayOfWeek) ;
void RTC_WriteAlarmDayOfYear(uint16 dayOfYear) ;

/* RTC read settings to set start values */
uint8 RTC_ReadSecond(void) ;
uint8 RTC_ReadMinute(void) ;
uint8 RTC_ReadHour(void) ;
uint8 RTC_ReadDayOfMonth(void) ;
uint8 RTC_ReadMonth(void) ;
uint16 RTC_ReadYear(void) ;

/* Alarm read settings */
uint8 RTC_ReadAlarmSecond(void) ;
uint8 RTC_ReadAlarmMinute(void) ;
uint8 RTC_ReadAlarmHour(void) ;
uint8 RTC_ReadAlarmDayOfMonth(void) ;
uint8 RTC_ReadAlarmMonth(void) ;
uint16 RTC_ReadAlarmYear(void) ;
uint8 RTC_ReadAlarmDayOfWeek(void) ;
uint16 RTC_ReadAlarmDayOfYear(void) ;

/* Set mask interrupt registers */
void RTC_WriteAlarmMask(uint8 mask) ;
void RTC_WriteIntervalMask(uint8 mask) ;

/* Read status register */
uint8 RTC_ReadStatus(void) CYREENTRANT;

#if (1u == RTC_DST_FUNC_ENABLE)

    /* DST write settings  */
    void RTC_WriteDSTMode(uint8 mode) ;
    void RTC_WriteDSTStartHour(uint8 hour) ;
    void RTC_WriteDSTStartDayOfMonth(uint8 dayOfMonth) 
                                                  ;
    void RTC_WriteDSTStartMonth(uint8 month) ;
    void RTC_WriteDSTStartDayOfWeek(uint8 dayOfWeek) 
                                                 ;
    void RTC_WriteDSTStartWeek(uint8 week) ;

    void RTC_WriteDSTStopHour(uint8 hour) ;
    void RTC_WriteDSTStopDayOfMonth(uint8 dayOfMonth) 
                                                 ;
    void RTC_WriteDSTStopMonth(uint8 month) ;
    void RTC_WriteDSTStopDayOfWeek(uint8 dayOfWeek) 
                                                ;
    void RTC_WriteDSTStopWeek(uint8 week) ;
    void RTC_WriteDSTOffset(uint8 offset) ;
    
#endif /* 1u == RTC_DST_FUNC_ENABLE */


/***************************************
*        API Constants
***************************************/

/* Number of the RTC_isr interrupt */
#define RTC_ISR_NUMBER             RTC_isr__INTC_NUMBER

/* Priority of the RTC_isr interrupt */
#define RTC_ISR_PRIORITY           RTC_isr__INTC_PRIOR_NUM

/* Time elapse constants */
#define RTC_MINUTE_ELAPSED         (59u)
#define RTC_HOUR_ELAPSED           (59u)
#define RTC_HALF_OF_DAY_ELAPSED    (12u)
#define RTC_DAY_ELAPSED            (23u)
#define RTC_WEEK_ELAPSED           (7u)
#define RTC_YEAR_ELAPSED           (12u)
#define RTC_DAYS_IN_WEEK           (7u)

/* Interval software register bit location */
#define RTC_INTERVAL_SEC_MASK      (0x01u)       /* SEC */
#define RTC_INTERVAL_MIN_MASK      (0x02u)       /* MIN */
#define RTC_INTERVAL_HOUR_MASK     (0x04u)       /* HOUR*/
#define RTC_INTERVAL_DAY_MASK      (0x08u)       /* DOM */
#define RTC_INTERVAL_WEEK_MASK     (0x10u)       /* DOM */
#define RTC_INTERVAL_MONTH_MASK    (0x20u)       /* MONTH */
#define RTC_INTERVAL_YEAR_MASK     (0x40u)       /* YEAR */

/* Alarm software register bit location */
#define RTC_ALARM_SEC_MASK         (0x01u)       /* SEC */
#define RTC_ALARM_MIN_MASK         (0x02u)       /* MIN */
#define RTC_ALARM_HOUR_MASK        (0x04u)       /* HOUR*/
#define RTC_ALARM_DAYOFWEEK_MASK   (0x08u)       /* DOW */
#define RTC_ALARM_DAYOFMONTH_MASK  (0x10u)       /* DOM */
#define RTC_ALARM_DAYOFYEAR_MASK   (0x20u)       /* DOY */
#define RTC_ALARM_MONTH_MASK       (0x40u)       /* MONTH */
#define RTC_ALARM_YEAR_MASK        (0x80u)       /* YEAR */

/* Status software register bit location */

/* DST stutus bit */
#define RTC_STATUS_DST             (0x01u)

/* Leap Year status bit */
#define RTC_STATUS_LY              (0x02u)

/* AM/PM status bit */
#define RTC_STATUS_AM_PM           (0x04u)

/* Alarm Active status bit */
#define RTC_STATUS_AA              (0x08u)

/* Days Of Week definition */
#define RTC_SUNDAY                       (7u)
#define RTC_MONDAY                       (1u)
#define RTC_TUESDAY                      (2u)
#define RTC_WEDNESDAY                    (3u)
#define RTC_THURDAY                      (4u)
#define RTC_FRIDAY                       (5u)
#define RTC_SATURDAY                     (6u)


/* Month definition */
#define RTC_JANUARY                (1u)
#define RTC_DAYS_IN_JANUARY        (31u)
#define RTC_FEBRUARY               (2u)
#define RTC_DAYS_IN_FEBRUARY       (28u)
#define RTC_MARCH                  (3u)
#define RTC_DAYS_IN_MARCH          (31u)
#define RTC_APRIL                  (4u)
#define RTC_DAYS_IN_APRIL          (30u)
#define RTC_MAY                    (5u)
#define RTC_DAYS_IN_MAY            (31u)
#define RTC_JUNE                   (6u)
#define RTC_DAYS_IN_JUNE           (30u)
#define RTC_JULY                   (7u)
#define RTC_DAYS_IN_JULY           (31u)
#define RTC_AUGUST                 (8u)
#define RTC_DAYS_IN_AUGUST         (31u)
#define RTC_SEPTEMBER              (9u)
#define RTC_DAYS_IN_SEPTEMBER      (30u)
#define RTC_OCTOBER                (10u)
#define RTC_DAYS_IN_OCTOBER        (31u)
#define RTC_NOVEMBER               (11u)
#define RTC_DAYS_IN_NOVEMBER       (30u)
#define RTC_DECEMBER               (12u)
#define RTC_DAYS_IN_DECEMBER       (31u)

/* DTS software registers bit location */

/* DST Enable */
#define RTC_DST_ENABLE             (0x01u)

/* Fixed data selected  */
#define RTC_DST_FIXDATE            (0x00u)

/* Relative data selected */
#define RTC_DST_RELDATE            (0x02u)

/* DST hour match flag */
#define RTC_DST_HOUR               (0x01u)

/* DST day of month match flag */
#define RTC_DST_DAYOFMONTH         (0x02u)

/* DST month match flag */
#define RTC_DST_MONTH              (0x04u)

#define RTC_MONTHS_IN_YEAR         (12u)
#define RTC_DAYS_IN_YEAR           (365u)
#define RTC_DAYS_IN_LEAP_YEAR      (366u)

/* Returns 1 if leap year, otherwise 0 */
#define RTC_LEAP_YEAR(year) ((!((year) % 400u) || (!((year) % 4u) && ((year) % 100u))) ? 0x01u : 0x00u)

/* Returns 1 if corresponding bit is set, otherwise 0 */
#define RTC_IS_BIT_SET(value, mask) (((mask) == ((value) & (mask))) ? 0x01u : 0x00u)

/* Set alarm if needed */
#define RTC_SET_ALARM(alarmCfg, alarmCur, status) \
    if((alarmCfg) && (RTC_IS_BIT_SET((alarmCur),(alarmCfg)))) \
    { \
        (status)  |= RTC_STATUS_AA; \
        (alarmCur) = 0u; \
    }

/* Following definitions are for the COMPATIBILITY ONLY, they are OBSOLETE. */
#define RTC_IsLeapYear         RTC_LEAP_YEAR
#define RTC_Dst                RTC_DSTIME
#define RTC_TimeDate           RTC_TIME_DATE

#define RTC_CurTimeDate        RTC_currentTimeDate
#define RTC_AlarmTimeDate      RTC_alarmCfgTimeDate

#if (1u == RTC_DST_FUNC_ENABLE)
    #define RTC_DstMode            RTC_dstModeType
    #define RTC_DstStartTimeDate   RTC_dstTimeDateStart
    #define RTC_DstStopTimeDate    RTC_dstTimeDateStop
    
    #define RTC_DstOffset          RTC_dstOffsetMin
    #define RTC_DstStatusStart     RTC_dstStartStatus
    #define RTC_DstStatusStop      RTC_dstStopStatus
#endif /* 1u == RTC_DST_FUNC_ENABLE */

#define RTC_AlarmMask      RTC_alarmCfgMask
#define RTC_AlarmStatus    RTC_alarmCurStatus
#define RTC_IntervalMask   RTC_intervalCfgMask
#define RTC_Status         RTC_statusDateTime
#define RTC_Dim            RTC_daysInMonths
#define RTC_Seq            RTC_monthTemplate


/***************************************
*    Registers
***************************************/

/* Timewheel Configuration Register 2 */
#define RTC_OPPS_CFG_REG           (* (reg8 *) CYREG_PM_TW_CFG2 )
#define RTC_OPPS_CFG_PTR           (  (reg8 *) CYREG_PM_TW_CFG2 )

/* Power Manager Interrupt Status Register */
#define RTC_OPPS_INT_SR_REG        (* (reg8 *) CYREG_PM_INT_SR )
#define RTC_OPPS_INT_SR_PTR        (  (reg8 *) CYREG_PM_INT_SR )


/***************************************
*    External Software Registers
***************************************/

extern RTC_TIME_DATE    RTC_alarmCfgTimeDate;
extern RTC_TIME_DATE    RTC_currentTimeDate;

#if (1u == RTC_DST_FUNC_ENABLE)
    extern volatile uint8             RTC_dstModeType;
    extern RTC_DSTIME     RTC_dstTimeDateStart;
    extern RTC_DSTIME     RTC_dstTimeDateStop;
    extern volatile uint8   RTC_dstOffsetMin;
    extern volatile uint8   RTC_dstStartStatus;
    extern volatile uint8   RTC_dstStopStatus;
#endif /* 1u == RTC_DST_FUNC_ENABLE */

extern volatile uint8       RTC_alarmCfgMask;
extern volatile uint8       RTC_alarmCurStatus;
extern volatile uint8       RTC_intervalCfgMask;
extern volatile uint8       RTC_statusDateTime;

extern const uint8 CYCODE   RTC_daysInMonths [RTC_MONTHS_IN_YEAR];
extern const uint8 CYCODE   RTC_monthTemplate [RTC_MONTHS_IN_YEAR];

    
/***************************************
*        Register Constants
****************************************/

#define RTC_OPPS_EN_MASK           (0x10u)
#define RTC_OPPSIE_EN_MASK         (0x20u)

/* Enable wakeup from the Sleeep low power mode */
#define RTC_PM_WAKEUP_CTW_1PPS     (0x80u)

#endif /* CY_RTC_RTC_H */


/* [] END OF FILE */
