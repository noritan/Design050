#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include <cydevice.h>
#include <cydevice_trm.h>

/* PWM_FAST_PWMUDB */
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB13_14_CTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB13_14_CTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB13_14_CTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB13_14_MSK
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB13_14_MSK
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB13_14_MSK
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_B0_UDB13_CTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB13_ST_CTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_B0_UDB13_CTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_B0_UDB13_ST_CTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x80u
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_B0_UDB13_MSK
#define PWM_FAST_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB12_13_A0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB12_13_A1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB12_13_D0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB12_13_D1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB12_13_F0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB12_13_F1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__A0_A1_REG CYREG_B0_UDB12_A0_A1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__A0_REG CYREG_B0_UDB12_A0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__A1_REG CYREG_B0_UDB12_A1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__D0_D1_REG CYREG_B0_UDB12_D0_D1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__D0_REG CYREG_B0_UDB12_D0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__D1_REG CYREG_B0_UDB12_D1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__F0_F1_REG CYREG_B0_UDB12_F0_F1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__F0_REG CYREG_B0_UDB12_F0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u0__F1_REG CYREG_B0_UDB12_F1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG CYREG_B0_UDB13_14_A0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG CYREG_B0_UDB13_14_A1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG CYREG_B0_UDB13_14_D0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG CYREG_B0_UDB13_14_D1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG CYREG_B0_UDB13_14_F0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG CYREG_B0_UDB13_14_F1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__A0_A1_REG CYREG_B0_UDB13_A0_A1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__A0_REG CYREG_B0_UDB13_A0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__A1_REG CYREG_B0_UDB13_A1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__D0_D1_REG CYREG_B0_UDB13_D0_D1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__D0_REG CYREG_B0_UDB13_D0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__D1_REG CYREG_B0_UDB13_D1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__F0_F1_REG CYREG_B0_UDB13_F0_F1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__F0_REG CYREG_B0_UDB13_F0
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__F1_REG CYREG_B0_UDB13_F1
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL
#define PWM_FAST_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG CYREG_B0_UDB13_MSK_ACTL

/* PWM_SLOW_PWMUDB */
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__7__MASK 0x80u
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__7__POS 7
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG CYREG_B0_UDB15_CTL
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB15_ST_CTL
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_REG CYREG_B0_UDB15_CTL
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__COUNT_ST_REG CYREG_B0_UDB15_ST_CTL
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__MASK 0x80u
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__PERIOD_REG CYREG_B0_UDB15_MSK
#define PWM_SLOW_PWMUDB_sCTRLReg_SyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB14_15_A0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB14_15_A1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB14_15_D0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB14_15_D1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB14_15_ACTL
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB14_15_F0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB14_15_F1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__A0_A1_REG CYREG_B0_UDB14_A0_A1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__A0_REG CYREG_B0_UDB14_A0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__A1_REG CYREG_B0_UDB14_A1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__D0_D1_REG CYREG_B0_UDB14_D0_D1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__D0_REG CYREG_B0_UDB14_D0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__D1_REG CYREG_B0_UDB14_D1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB14_ACTL
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__F0_F1_REG CYREG_B0_UDB14_F0_F1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__F0_REG CYREG_B0_UDB14_F0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u0__F1_REG CYREG_B0_UDB14_F1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__A0_A1_REG CYREG_B0_UDB15_A0_A1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__A0_REG CYREG_B0_UDB15_A0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__A1_REG CYREG_B0_UDB15_A1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__D0_D1_REG CYREG_B0_UDB15_D0_D1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__D0_REG CYREG_B0_UDB15_D0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__D1_REG CYREG_B0_UDB15_D1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG CYREG_B0_UDB15_ACTL
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__F0_F1_REG CYREG_B0_UDB15_F0_F1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__F0_REG CYREG_B0_UDB15_F0
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__F1_REG CYREG_B0_UDB15_F1
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__MSK_DP_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL
#define PWM_SLOW_PWMUDB_sP16_pwmdp_u1__PER_DP_AUX_CTL_REG CYREG_B0_UDB15_MSK_ACTL

/* Clock_32k */
#define Clock_32k__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_32k__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_32k__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_32k__CFG2_SRC_SEL_MASK 0x07u
#define Clock_32k__INDEX 0x00u
#define Clock_32k__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_32k__PM_ACT_MSK 0x01u
#define Clock_32k__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_32k__PM_STBY_MSK 0x01u

/* LED3_P6_2 */
#define LED3_P6_2__0__MASK 0x04u
#define LED3_P6_2__0__PC CYREG_PRT6_PC2
#define LED3_P6_2__0__PORT 6u
#define LED3_P6_2__0__SHIFT 2
#define LED3_P6_2__AG CYREG_PRT6_AG
#define LED3_P6_2__AMUX CYREG_PRT6_AMUX
#define LED3_P6_2__BIE CYREG_PRT6_BIE
#define LED3_P6_2__BIT_MASK CYREG_PRT6_BIT_MASK
#define LED3_P6_2__BYP CYREG_PRT6_BYP
#define LED3_P6_2__CTL CYREG_PRT6_CTL
#define LED3_P6_2__DM0 CYREG_PRT6_DM0
#define LED3_P6_2__DM1 CYREG_PRT6_DM1
#define LED3_P6_2__DM2 CYREG_PRT6_DM2
#define LED3_P6_2__DR CYREG_PRT6_DR
#define LED3_P6_2__INP_DIS CYREG_PRT6_INP_DIS
#define LED3_P6_2__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define LED3_P6_2__LCD_EN CYREG_PRT6_LCD_EN
#define LED3_P6_2__MASK 0x04u
#define LED3_P6_2__PORT 6u
#define LED3_P6_2__PRT CYREG_PRT6_PRT
#define LED3_P6_2__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define LED3_P6_2__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define LED3_P6_2__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define LED3_P6_2__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define LED3_P6_2__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define LED3_P6_2__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define LED3_P6_2__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define LED3_P6_2__PS CYREG_PRT6_PS
#define LED3_P6_2__SHIFT 2
#define LED3_P6_2__SLW CYREG_PRT6_SLW

/* LED4_P6_3 */
#define LED4_P6_3__0__MASK 0x08u
#define LED4_P6_3__0__PC CYREG_PRT6_PC3
#define LED4_P6_3__0__PORT 6u
#define LED4_P6_3__0__SHIFT 3
#define LED4_P6_3__AG CYREG_PRT6_AG
#define LED4_P6_3__AMUX CYREG_PRT6_AMUX
#define LED4_P6_3__BIE CYREG_PRT6_BIE
#define LED4_P6_3__BIT_MASK CYREG_PRT6_BIT_MASK
#define LED4_P6_3__BYP CYREG_PRT6_BYP
#define LED4_P6_3__CTL CYREG_PRT6_CTL
#define LED4_P6_3__DM0 CYREG_PRT6_DM0
#define LED4_P6_3__DM1 CYREG_PRT6_DM1
#define LED4_P6_3__DM2 CYREG_PRT6_DM2
#define LED4_P6_3__DR CYREG_PRT6_DR
#define LED4_P6_3__INP_DIS CYREG_PRT6_INP_DIS
#define LED4_P6_3__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define LED4_P6_3__LCD_EN CYREG_PRT6_LCD_EN
#define LED4_P6_3__MASK 0x08u
#define LED4_P6_3__PORT 6u
#define LED4_P6_3__PRT CYREG_PRT6_PRT
#define LED4_P6_3__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define LED4_P6_3__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define LED4_P6_3__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define LED4_P6_3__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define LED4_P6_3__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define LED4_P6_3__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define LED4_P6_3__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define LED4_P6_3__PS CYREG_PRT6_PS
#define LED4_P6_3__SHIFT 3
#define LED4_P6_3__SLW CYREG_PRT6_SLW

/* RTC_1_isr */
#define RTC_1_isr__ES2_PATCH 0u
#define RTC_1_isr__INTC_CLR_EN_REG CYREG_INTC_CLR_EN0
#define RTC_1_isr__INTC_CLR_PD_REG CYREG_INTC_CLR_PD0
#define RTC_1_isr__INTC_MASK 0x01u
#define RTC_1_isr__INTC_NUMBER 0u
#define RTC_1_isr__INTC_PRIOR_NUM 7u
#define RTC_1_isr__INTC_PRIOR_REG CYREG_INTC_PRIOR0
#define RTC_1_isr__INTC_SET_EN_REG CYREG_INTC_SET_EN0
#define RTC_1_isr__INTC_SET_PD_REG CYREG_INTC_SET_PD0
#define RTC_1_isr__INTC_VECT (CYREG_INTC_VECT_MBASE+0x00u)

/* SW2_P6_1 */
#define SW2_P6_1__0__MASK 0x02u
#define SW2_P6_1__0__PC CYREG_PRT6_PC1
#define SW2_P6_1__0__PORT 6u
#define SW2_P6_1__0__SHIFT 1
#define SW2_P6_1__AG CYREG_PRT6_AG
#define SW2_P6_1__AMUX CYREG_PRT6_AMUX
#define SW2_P6_1__BIE CYREG_PRT6_BIE
#define SW2_P6_1__BIT_MASK CYREG_PRT6_BIT_MASK
#define SW2_P6_1__BYP CYREG_PRT6_BYP
#define SW2_P6_1__CTL CYREG_PRT6_CTL
#define SW2_P6_1__DM0 CYREG_PRT6_DM0
#define SW2_P6_1__DM1 CYREG_PRT6_DM1
#define SW2_P6_1__DM2 CYREG_PRT6_DM2
#define SW2_P6_1__DR CYREG_PRT6_DR
#define SW2_P6_1__INP_DIS CYREG_PRT6_INP_DIS
#define SW2_P6_1__INTSTAT CYREG_PICU6_INTSTAT
#define SW2_P6_1__LCD_COM_SEG CYREG_PRT6_LCD_COM_SEG
#define SW2_P6_1__LCD_EN CYREG_PRT6_LCD_EN
#define SW2_P6_1__MASK 0x02u
#define SW2_P6_1__PORT 6u
#define SW2_P6_1__PRT CYREG_PRT6_PRT
#define SW2_P6_1__PRTDSI__CAPS_SEL CYREG_PRT6_CAPS_SEL
#define SW2_P6_1__PRTDSI__DBL_SYNC_IN CYREG_PRT6_DBL_SYNC_IN
#define SW2_P6_1__PRTDSI__OE_SEL0 CYREG_PRT6_OE_SEL0
#define SW2_P6_1__PRTDSI__OE_SEL1 CYREG_PRT6_OE_SEL1
#define SW2_P6_1__PRTDSI__OUT_SEL0 CYREG_PRT6_OUT_SEL0
#define SW2_P6_1__PRTDSI__OUT_SEL1 CYREG_PRT6_OUT_SEL1
#define SW2_P6_1__PRTDSI__SYNC_OUT CYREG_PRT6_SYNC_OUT
#define SW2_P6_1__PS CYREG_PRT6_PS
#define SW2_P6_1__SHIFT 1
#define SW2_P6_1__SLW CYREG_PRT6_SLW
#define SW2_P6_1__SNAP CYREG_PICU6_SNAP

/* Miscellaneous */
/* -- WARNING: define names containing LEOPARD or PANTHER are deprecated and will be removed in a future release */
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIG_FASTBOOT_ENABLED 0
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_DIE_LEOPARD
#define BCLK__BUS_CLK__HZ 48000000U
#define BCLK__BUS_CLK__KHZ 48000U
#define BCLK__BUS_CLK__MHZ 48U
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_DIE_PANTHER 3u
#define CYDEV_CHIP_DIE_PSOC4A 2u
#define CYDEV_CHIP_DIE_PSOC5LP 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC3
#define CYDEV_CHIP_JTAG_ID 0x1E028069u
#define CYDEV_CHIP_MEMBER_4A 2u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 4u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_3A
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_3A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REV_LEOPARD_PRODUCTION
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CONFIGURATION_CLEAR_SRAM 1
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_REQXRES 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DEBUG_ENABLE_MASK 0x01u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000000u
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5
#define CYDEV_VIO3_MV 5000
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */