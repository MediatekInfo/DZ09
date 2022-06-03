// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
/*
* This file is part of the DZ09 project.
*
* Copyright (C) 2022 AJScorp
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; version 2 of the License.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/
#ifndef _DPRAM_H_
#define _DPRAM_H_

#define DPRAM_BASE(v)                       (DPRAM_CPU_BASE + 2 * (v))

#define DP_DSP_TASK_STATUS_BASE             0x3A00                                                                          /* 0x7400 */

#define DP_DSP_STATUS                       (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0000))            /* 0x7400 */
#define DP_MCU_STATUS                       (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0001))            /* 0x7402 */
#define DP_DSP_STATUS_MTCMOS                (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0002))            /* 0x7404 */
#define DP_MCU_STATUS_MTCMOS                (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0003))            /* 0x7406 */
#define DEBUG_ASSERT_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0004))            /* 0x7408 */
#define DTIRQ_DEBUG_ASSERT_CHECK            (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0005))            /* 0x740A */
#define DP_RX_WIN_COUNT                     (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0006))            /* 0x740C */
#define DP2_RX_S0_CD_DONE                   (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0007))            /* 0x740E */
#define DP_SLOW_IDLE_DIVIDER                (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0008))            /* 0x7410 */
#define DP_DSP_ROM_VERSION                  (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0009))            /* 0x7412 */

#define DP_RX_WINDOW_BASE                   (DP_DSP_TASK_STATUS_BASE + 0x000A)                                              /* 0x7414 */

#define DP_RX_WIN0_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0000))                  /* 0x7414 */
#define DP_RX_WIN1_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0001))                  /* 0x7416 */
#define DP_RX_WIN2_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0002))                  /* 0x7418 */
#define DP_RX_WIN3_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0003))                  /* 0x741A */
#define DP_RX_WIN4_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0004))                  /* 0x741C */
#define DP_RX_WIN5_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0005))                  /* 0x741E */
#define DP_RX_WIN6_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0006))                  /* 0x7420 */
#define DP_RX_WIN7_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0007))                  /* 0x7422 */
#define DP_RX_WIN0_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0008))                  /* 0x7424 */
#define DP_RX_WIN1_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0009))                  /* 0x7426 */
#define DP_RX_WIN2_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x000A))                  /* 0x7428 */
#define DP_RX_WIN3_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x000B))                  /* 0x742A */
#define DP_RX_WIN4_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x000C))                  /* 0x742C */
#define DP_RX_WIN5_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x000D))                  /* 0x742E */

#define DP2_TX_WINDOW_BASE                  (DP_RX_WINDOW_BASE + 0x000E)                                                    /* 0x7430 */

#define DP2_TX_WIN0_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0000))                 /* 0x7430 */
#define DP2_TX_WIN1_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0001))                 /* 0x7432 */
#define DP2_TX_WIN2_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0002))                 /* 0x7434 */
#define DP2_TX_WIN3_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0003))                 /* 0x7436 */
#define DP2_TX_WIN4_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0004))                 /* 0x7438 */

#define DP2_ENCRYPTION_BASE                 (DP2_TX_WINDOW_BASE + 0x0005)                                                   /* 0x743A */

#define DP2_CRYPT_PAR_0                     (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0000))                /* 0x743A */
#define DP2_ENCRYP_KEY_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0001))                /* 0x743C */
#define DP2_ENCRYP_KEY_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0002))                /* 0x743E */
#define DP2_ENCRYP_KEY_3                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0003))                /* 0x7440 */
#define DP2_ENCRYP_KEY_4                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0004))                /* 0x7442 */

#define DP_EQ_CHANNEL_CODEC_BASE            (DP2_ENCRYPTION_BASE + 0x0005)                                                  /* 0x7444 */

#define DP_CHEST_RENULL_SN_ALPHA            (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0000))           /* 0x7444 */
#define DP_RX_BUFFER_LEN                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0001))           /* 0x7446 */
#define DP_NB_TRX                           (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0002))           /* 0x7448 */
#define DP_FCCH_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0003))           /* 0x744A */
#define DP_FCB_CONSEC                       (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0004))           /* 0x744C */
#define DP_FCB1_LANDA_FXP                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0005))           /* 0x744E */
#define DP_FCB2_LANDA_FXP                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0006))           /* 0x7450 */
#define DP_FCB1_COST_THRESHOLD_FXP          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0007))           /* 0x7452 */
#define DP_FCB2_COST_THRESHOLD_FXP          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0008))           /* 0x7454 */
#define DP_FCB_FOE_TH                       (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0009))           /* 0x7456 */
#define DP_SHORT_FB_BURST_LEN               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000A))           /* 0x7458 */
#define DP_SHORT_FB_RESCALING_FACTOR        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000B))           /* 0x745A */
#define DP_SHORT_FB_RESOLUTION              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000C))           /* 0x745C */
#define DP_SHORT_FB_DC_AVE_LEN              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000D))           /* 0x745E */
#define DP_SHORT_FB_BER_THR                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000E))           /* 0x7460 */
#define DP_SHORT_FB_DIST_THR                (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000F))           /* 0x7462 */
#define DP_SHORT_SB_BURST_LEN               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0010))           /* 0x7464 */
#define DP_SHORT_SB_RESCALING_FACTOR        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0011))           /* 0x7466 */
#define DP_SHORT_SB_RESOLUTION              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0012))           /* 0x7468 */
#define DP_FB_2ND_INIT_FLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0013))           /* 0x746A */
#define DP_CC_FLAG                          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0014))           /* 0x746C */
#define DP_PM_LENGTH_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0015))           /* 0x746E */
#define DP_PHASE_IMB_FACTOR                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0016))           /* 0x7470 */
#define DP_STEPDC_THRES                     (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0017))           /* 0x7472 */
#define DP_CHEST_LEN_ALPHA                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0018))           /* 0x7474 */
#define DP_STATIC_STATE                     (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0019))           /* 0x7476 */
#define DP_CW_POSITION                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x001A))           /* 0x7478 */
#define DP_QBIT_CW_SWITCH                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x001B))           /* 0x747A */
#define DP_NB_RANGE_WIN                     (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x001C))           /* 0x747C */

#define DP_EQ_SAIC_BASE                     (DP_EQ_CHANNEL_CODEC_BASE + 0x001D)                                             /* 0x747E */

#define DP_RX_SAIC_SWITCH                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0000))                    /* 0x747E */
#define DP_RX_SAIC_THRES                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0001))                    /* 0x7480 */
#define DP_EPSK_SAIC_PWR_TH                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0002))                    /* 0x7482 */
#define DP_EPSK_SAIC_SN_TH                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0003))                    /* 0x7484 */
#define DP_ANT_PWR_OFFSET                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0004))                    /* 0x7486 */
#define DP_DSP_PWR_UNDERFLOW                (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0005))                    /* 0x7488 */
#define DP_BEP_K1_GMSK                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0006))                    /* 0x748A */
#define DP_BEP_K2_GMSK                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0007))                    /* 0x748C */
#define DP_BEP_K1_EPSK                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0008))                    /* 0x748E */
#define DP_BEP_K2_EPSK                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0009))                    /* 0x7490 */
#define DP_BEP_K1_GMSK_SAIC_ON              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x000A))                    /* 0x7492 */
#define DP_BEP_K2_GMSK_SAIC_ON              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x000B))                    /* 0x7494 */
#define DP_BEP_K1_EPSK_SAIC_ON              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x000C))                    /* 0x7496 */
#define DP_BEP_K2_EPSK_SAIC_ON              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x000D))                    /* 0x7498 */

#define DP_EQ_CONTROL_BASE                  (DP_EQ_SAIC_BASE + 0x000E)                                                      /* 0x7498 */

#define DP_MODDET_THRES                     (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0000))                 /* 0x749A */
#define DP_CHEST_LEN35_SN_TH                (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0001))                 /* 0x749C */
#define DP_CHEST_LEN_TSNR                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0002))                 /* 0x749E */
#define DP_CHEST_LEN_T23                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0003))                 /* 0x74A0 */
#define DP_CHEST_LEN_T35                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0004))                 /* 0x74A2 */
#define DP_CHEST_LEN_T57                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0005))                 /* 0x74A4 */
#define DP_CHEST_NT_GMSK                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0006))                 /* 0x74A6 */
#define DP_CHEST_NT_EPSK                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0007))                 /* 0x74A8 */
#define DP_CHEST_LEN_ALPHA_1THR             (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0008))                 /* 0x74AA */
#define DP_CHEST_LEN_ALPHA_0THR             (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0009))                 /* 0x74AC */
#define DP_CHEST_NULL_SNTHR_H               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000A))                 /* 0x74AE */
#define DP_CHEST_NULL_SNTHR_L               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000B))                 /* 0x74B0 */
#define DP_CHEST_RENULL_TH                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000C))                 /* 0x74B2 */
#define DP_CHEST_RENULL_ALPHA_CNT_TH        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000D))                 /* 0x74B4 */
#define DP_CHEST_SAIC_PARA_NB               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000E))                 /* 0x74B6 */
#define DP_CHEST_SAIC_PARA_SB               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000F))                 /* 0x74B8 */
#define DP_CHEST_SAIC_SP_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0010))                 /* 0x74BA */
#define DP_CHEST_SAIC_LEN_T35_SNH           (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0011))                 /* 0x74BC */
#define DP_CHEST_SAIC_LEN_T35_SNL           (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0012))                 /* 0x74BE */
#define DP_CHEST_SAIC_CIRTHRES              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0013))                 /* 0x74C0 */
#define DP_AMR_LS_DC_SNTHR                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0014))                 /* 0x74C2 */
#define DP_EPSK_SAIC_PARA                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0015))                 /* 0x74C4 */
#define DP_SINR_GMSK_FACTOR                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0016))                 /* 0x74C6 */
#define DP_SINR_EPSK_FACTOR_SAIC_ON         (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0017))                 /* 0x74C8 */
#define DP_SINR_EPSK_FACTOR_SAIC_OFF        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0018))                 /* 0x74CA */
#define DP_FOE_SINR_SHIFT                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0019))                 /* 0x74CC */
#define DP_FOE_GMSK_FACTOR                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001A))                 /* 0x74CE */
#define DP_FOE_EPSK_FACTOR                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001B))                 /* 0x74D0 */
#define DP_FOE_LEN                          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001C))                 /* 0x74D2 */
#define DP_FOE_INV_SUMK2                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001D))                 /* 0x74D4 */
#define DP_CS4_BEP_TH1                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001E))                 /* 0x74D6 */
#define DP_EQCFG_PFLEN                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001F))                 /* 0x74D8 */
#define DP_EQCFG_LMS                        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0020))                 /* 0x74DA */
#define DP_EQCFG_LMSTHRES                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0021))                 /* 0x74DC */
#define DP_EQCFG_PLL                        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0022))                 /* 0x74DE */
#define DP_EQCFG_PLLTHRES                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0023))                 /* 0x74E0 */
#define DP_EQCFG_DARPPLL                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0024))                 /* 0x74E2 */
#define DP_EQCFG_DARPPLLTHRES               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0025))                 /* 0x74E4 */
#define DP_EQCFG_SAIC_LMS_STEPSIZE          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0026))                 /* 0x74E6 */
#define DP_SINR_FWBW_THRES                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0027))                 /* 0x74E8 */

#define DP_VAMOS_CONTROL_BASE               (DP_EQ_CONTROL_BASE + 0x0028)                                                   /* 0x74EA */

#define DP_VAMOS_ENABLE                     (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0000))              /* 0x74EA */
#define DP_VAMOS_TSCSNR_SH                  (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0001))              /* 0x74EC */
#define DP_VAMOS_TSCSNR_CONST               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0002))              /* 0x74EE */
#define DP_VAMOS_BEP_K3                     (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0003))              /* 0x74F0 */
#define DP_VAMOS_BEP_K4                     (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0004))              /* 0x74F2 */
#define DP_VAMOS_SAIC_PARA                  (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0005))              /* 0x74F4 */
#define DP2_VAMOS_BFI_MEAN_SNTH             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0006))              /* 0x74F6 */
#define DP2_VAMOS_BFI_D_TH                  (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0007))              /* 0x74F8 */
#define DP_VAMOS_BFI_SN_THRES               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0008))              /* 0x74FA */
#define DP_FOE_AQPSK_FACTOR                 (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0009))              /* 0x74FC */
#define DP_SOC3_ENABLE_DC_CANCELLATION      (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000A))              /* 0x74FE */
#define DP_VAMOS_ZETA_TH                    (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000B))              /* 0x7500 */
#define DP_VAMOS_LS_DC_SNTHR                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000C))              /* 0x7502 */
#define DP_VAMOS_LS_DC_PTHR1                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000D))              /* 0x7504 */
#define DP_VAMOS_LS_DC_PTHR2                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000E))              /* 0x7506 */

#define DP_VAMOS_ZETA_BASE                  (DP_VAMOS_CONTROL_BASE + 0x0010)                                                /* 0x7508 */

#define DP_VAMOS_ZETA_THR_10                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0000))                 /* 0x7508 */
#define DP_VAMOS_ZETA_THR_11                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0001))                 /* 0x750A */
#define DP_VAMOS_ZETA_THR_12                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0002))                 /* 0x750C */
#define DP_VAMOS_ZETA_THR_13                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0003))                 /* 0x750E */
#define DP_VAMOS_ZETA_THR_20                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0004))                 /* 0x7510 */
#define DP_VAMOS_ZETA_THR_21                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0005))                 /* 0x7512 */
#define DP_VAMOS_ZETA_THR_22                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0006))                 /* 0x7514 */
#define DP_VAMOS_ZETA_THR_23                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0007))                 /* 0x7516 */
#define DP_VAMOS_ZETA_THR_30                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0008))                 /* 0x7518 */
#define DP_VAMOS_ZETA_THR_31                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0009))                 /* 0x751C */
#define DP_VAMOS_ZETA_THR_32                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000A))                 /* 0x751E */
#define DP_VAMOS_ZETA_THR_33                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000B))                 /* 0x7520 */
#define DP_VAMOS_ZETA_THR_40                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000C))                 /* 0x7522 */
#define DP_VAMOS_ZETA_THR_41                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000D))                 /* 0x7524 */
#define DP_VAMOS_ZETA_THR_50                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000E))                 /* 0x7526 */
#define DP_VAMOS_ZETA_THR_51                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000F))                 /* 0x7528 */

#define DP_VAMOS_BEP_BASE                   (DP_VAMOS_ZETA_BASE + 0x0010)                                                   /* 0x752A */

#define DP_VAMOS_BEP_SCALING_0              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0000))                  /* 0x752A */
#define DP_VAMOS_BEP_OFFSET_0               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0001))                  /* 0x752C */
#define DP_VAMOS_BEP_SCALING_1              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0002))                  /* 0x752E */
#define DP_VAMOS_BEP_OFFSET_1               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0003))                  /* 0x7530 */
#define DP_VAMOS_BEP_SCALING_2              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0004))                  /* 0x7532 */
#define DP_VAMOS_BEP_OFFSET_2               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0005))                  /* 0x7534 */
#define DP_VAMOS_BEP_SCALING_3              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0006))                  /* 0x7536 */
#define DP_VAMOS_BEP_OFFSET_3               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0007))                  /* 0x7538 */
#define DP_VAMOS_BEP_SCALING_4              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0008))                  /* 0x753A */
#define DP_VAMOS_BEP_OFFSET_4               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0009))                  /* 0x753C */
#define DP_VAMOS_BEP_SCALING_5              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000A))                  /* 0x753E */
#define DP_VAMOS_BEP_OFFSET_5               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000B))                  /* 0x7540 */
#define DP_VAMOS_BEP_SCALING_6              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000C))                  /* 0x7542 */
#define DP_VAMOS_BEP_OFFSET_6               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000D))                  /* 0x7544 */
#define DP_VAMOS_BEP_SCALING_7              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000E))                  /* 0x7546 */
#define DP_VAMOS_BEP_OFFSET_7               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000F))                  /* 0x7548 */
#define DP_VAMOS_BEP_SCALING_8              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0010))                  /* 0x754A */
#define DP_VAMOS_BEP_OFFSET_8               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0011))                  /* 0x754C */
#define DP_VAMOS_BEP_SCALING_9              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0012))                  /* 0x754E */
#define DP_VAMOS_BEP_OFFSET_9               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0013))                  /* 0x7550 */
#define DP_VAMOS_BEP_SCALING_10             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0014))                  /* 0x7552 */
#define DP_VAMOS_BEP_OFFSET_10              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0015))                  /* 0x7554 */
#define DP_VAMOS_BEP_SCALING_11             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0016))                  /* 0x7556 */
#define DP_VAMOS_BEP_OFFSET_11              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0017))                  /* 0x7558 */
#define DP_VAMOS_BEP_SCALING_12             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0018))                  /* 0x755A */
#define DP_VAMOS_BEP_OFFSET_12              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0019))                  /* 0x755C */

#define DP_VAMOS_AMRQI_BASE                 (DP_VAMOS_BEP_BASE + 0x001A)                                                    /* 0x755E */

#define DP_VAMOS_AMRQI_SCALING_0            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0000))                /* 0x755E */
#define DP_VAMOS_AMRQI_OFFSET_0             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0001))                /* 0x7560 */
#define DP_VAMOS_AMRQI_SCALING_1            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0002))                /* 0x7562 */
#define DP_VAMOS_AMRQI_OFFSET_1             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0003))                /* 0x7564 */
#define DP_VAMOS_AMRQI_SCALING_2            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0004))                /* 0x7566 */
#define DP_VAMOS_AMRQI_OFFSET_2             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0005))                /* 0x7568 */
#define DP_VAMOS_AMRQI_SCALING_3            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0006))                /* 0x756A */
#define DP_VAMOS_AMRQI_OFFSET_3             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0007))                /* 0x756C */
#define DP_VAMOS_AMRQI_SCALING_4            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0008))                /* 0x756E */
#define DP_VAMOS_AMRQI_OFFSET_4             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0009))                /* 0x7570 */
#define DP_VAMOS_AMRQI_SCALING_5            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000A))                /* 0x7572 */
#define DP_VAMOS_AMRQI_OFFSET_5             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000B))                /* 0x7574 */
#define DP_VAMOS_AMRQI_SCALING_6            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000C))                /* 0x7576 */
#define DP_VAMOS_AMRQI_OFFSET_6             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000D))                /* 0x7578 */
#define DP_VAMOS_AMRQI_SCALING_7            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000E))                /* 0x757A */
#define DP_VAMOS_AMRQI_OFFSET_7             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000F))                /* 0x757C */
#define DP_VAMOS_AMRQI_SCALING_8            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0010))                /* 0x757E */
#define DP_VAMOS_AMRQI_OFFSET_8             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0011))                /* 0x7580 */
#define DP_VAMOS_AMRQI_SCALING_9            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0012))                /* 0x7582 */
#define DP_VAMOS_AMRQI_OFFSET_9             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0013))                /* 0x7584 */
#define DP_VAMOS_AMRQI_SCALING_10           (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0014))                /* 0x7586 */
#define DP_VAMOS_AMRQI_OFFSET_10            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0015))                /* 0x7588 */
#define DP_VAMOS_AMRQI_SCALING_11           (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0016))                /* 0x758A */
#define DP_VAMOS_AMRQI_OFFSET_11            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0017))                /* 0x758C */
#define DP_VAMOS_AMRQI_SCALING_12           (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0018))                /* 0x758E */
#define DP_VAMOS_AMRQI_OFFSET_12            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0019))                /* 0x7590 */

#define DP_IRDMA_BASE                       (DP_VAMOS_AMRQI_BASE + 0x001A)                                                  /* 0x7592 */

#define DP_IRDMA_LA                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0000))                      /* 0x7592 */
#define DP_IRDMA_UA                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0001))                      /* 0x7594 */
#define DP_IRDMA_FB                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0002))                      /* 0x7596 */
#define DP_IRDMA_SB                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0003))                      /* 0x7598 */
#define DP_IRDMA_TB                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0004))                      /* 0x759A */
#define DP_IRDMA_ENA                        (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0005))                      /* 0x759C */
#define DP_BUF_SIZE                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0006))                      /* 0x759E */
#define DP_SUB_BUF_NUM                      (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0007))                      /* 0x75A0 */

#define DP_DEBUG_CTRL_BASE                  (DP_IRDMA_BASE + 0x0008)                                                        /* 0x75A2 */

#define DP_DB_CNTL                          (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0000))                 /* 0x75A2 */
#define DP_DB_FLT_MD0                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0001))                 /* 0x75A4 */
#define DP_DB_FLT_MD1                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0002))                 /* 0x75A6 */
#define DP_DB_FLT_MD2                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0003))                 /* 0x75A8 */
#define DP_DB_FLT_MD3                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0004))                 /* 0x75AA */
#define DP_DB_FLT_SP                        (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0005))                 /* 0x75AC */
#define SPH_IRDBG_FLT                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0005))                 /* 0x75AC */
#define DP_DB_FLT_AU                        (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0006))                 /* 0x75AE */
#define DP_DB_PTR                           (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0007))                 /* 0x75B0 */

#define DP_MCU_DEBUG_INFO_BASE              (DP_DEBUG_CTRL_BASE + 0x0008)                                                   /* 0x75B2 */

#define DP_MCU_TQWRAP                       (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0000))             /* 0x75B2 */
#define DP_MCU_AFC                          (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0001))             /* 0x75B4 */
#define DP_MCU_ARFCN_WIN0                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0002))             /* 0x75B6 */
#define DP_MCU_ARFCN_WIN1                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0003))             /* 0x75B8 */
#define DP_MCU_ARFCN_WIN2                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0004))             /* 0x75BA */
#define DP_MCU_ARFCN_WIN3                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0005))             /* 0x75BC */
#define DP_MCU_ARFCN_WIN4                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0006))             /* 0x75BE */
#define DP_MCU_AGC_WIN0                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0007))             /* 0x75C0 */
#define DP_MCU_AGC_WIN1                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0008))             /* 0x75C2 */
#define DP_MCU_AGC_WIN2                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0009))             /* 0x75C4 */
#define DP_MCU_AGC_WIN3                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x000A))             /* 0x75C6 */
#define DP_MCU_AGC_WIN4                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x000B))             /* 0x75C8 */
#define DP_MCU_AGC_WIN5                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x000C))             /* 0x75CA */

#define DP_LOGI_CHANNEL_BASE                (DP_MCU_DEBUG_INFO_BASE + 0x000D)                                               /* 0x75CC */

#define DP_GSM_MODE                         (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0000))               /* 0x75CC */
#define DP_TCH_S0_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0001))               /* 0x75CE */
#define DP_TCH_S1_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0002))               /* 0x75D0 */
#define DP_TCH_S2_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0003))               /* 0x75D2 */
#define DP_TCH_S3_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0004))               /* 0x75D4 */
#define DP_TCH_S4_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0005))               /* 0x75D6 */
#define DP_SACCH_S0_POS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0006))               /* 0x75D8 */
#define DP_NB_TSC                           (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0007))               /* 0x75DA */
#define DP2_TX_GPRS_CONSTELLATION0          (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0008))               /* 0x75DC */
#define DP2_TX_GPRS_CONSTELLATION           (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0008))               /* 0x75DC */
#define DP2_TX_GPRS_CONSTELLATION1          (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0009))               /* 0x75DE */
#define DP2_FAST_PCH_ENABLE                 (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000A))               /* 0x75E0 */
#define DP2_REPEATED_ACCH_GOOD_FLAG         (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000B))               /* 0x75E2 */
#define DP2_REPEATED_ACCH_ENABLE_FLAG       (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000C))               /* 0x75E4 */
#define DP2_2ND_CD_ENABLE_FLAGS             (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000D))               /* 0x75E6 */
#define DP2_2ND_CD_TYPE                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000E))               /* 0x75E8 */
#define DP2_2ND_CD_LENGHT_INFO              (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000F))               /* 0x75EA */
#define DP2_2ND_CD_GOOD_FLAGS               (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0010))               /* 0x75EC */
#define DP2_FACCH_LIKE_THRES                (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0011))               /* 0x75EE */
#define DP2_FACCH_LIKE_FLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0012))               /* 0x75F0 */
#define DP2_FACCH_THRES                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0013))               /* 0x75F2 */
#define DP2_BFI_MEAN_SNTH                   (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0014))               /* 0x75F4 */
#define DP2_BFI_D_TH                        (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0015))               /* 0x75F6 */
#define DP_BFI_SN_THRES                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0016))               /* 0x75F8 */
#define DP_LP_BACK_MODE                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0017))               /* 0x75FA */

#define DP_EGPRS_CHANNEL_CODEC_BASE         (DP_LOGI_CHANNEL_BASE + 0x0018)                                                 /* 0x75FC */

#define DP2_EDGE_S0_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0000))        /* 0x75FC */
#define DP2_EDGE_S1_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0001))        /* 0x75FE */
#define DP2_EDGE_S2_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0002))        /* 0x7600 */
#define DP2_EDGE_S3_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0003))        /* 0x7602 */
#define DP2_EDGE_S4_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0004))        /* 0x7604 */
#define DP2_EDGE_SRB_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0005))        /* 0x7606 */
#define DP2_IR_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0006))        /* 0x7608 */
#define DP2_RLC_WIN_SIZE                    (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0007))        /* 0x760A */
#define DP2_RLC_VQ                          (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0008))        /* 0x760C */
#define DP2_IR_DEC_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0009))        /* 0x760E */
#define DP2_IR_MEM_THRE_HIGH                (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000A))        /* 0x7610 */
#define DP2_IR_MEM_THRE_LOW                 (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000B))        /* 0x7612 */
#define DP2_IR_MEM_ADDR_L                   (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000C))        /* 0x7614 */
#define DP2_IR_MEM_ADDR_H                   (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000D))        /* 0x7616 */
#define DP2_AVAIL_IR_MEM_BLOCK_NUM          (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000E))        /* 0x7618 */
#define DP2_IR_MEM_BLOCK_NUM                (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000F))        /* 0x761A */

#define DP2_PERI_CTRL_BASE                  (DP_EGPRS_CHANNEL_CODEC_BASE + 0x0010)                                          /* 0x761C */

#define DP2_PERI_CTRL_CONFIG                (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0000))                 /* 0x761C */
#define DP2_PERI_CTRL_DSP_READ1             (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0001))                 /* 0x761E */
#define DP2_PERI_CTRL_DSP_WRITE1            (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0002))                 /* 0x7620 */
#define DP2_PERI_CTRL_DSP_READ2             (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0003))                 /* 0x7622 */
#define DP2_PERI_CTRL_DSP_WRITE2            (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0004))                 /* 0x7624 */
#define DP2_PERI_CTRL_DSP_READ3             (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0005))                 /* 0x7626 */
#define DP2_PERI_CTRL_DSP_WRITE3            (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0006))                 /* 0x7628 */

#define DP2_AMR_CTRL_BASE                   (DP2_PERI_CTRL_BASE + 0x0007)                                                   /* 0x762A */

#define DP2_AMR_T1                          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0000))                  /* 0x762A */
#define DP2_AMR_T2                          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0001))                  /* 0x762C */
#define DP2_AMR_T3                          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0002))                  /* 0x762E */
#define DP2_AMR_FLAGS                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0003))                  /* 0x7630 */
#define DP2_AMR_ICM                         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0004))                  /* 0x7632 */
#define DP2_AMR_DL_ACS_01                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0005))                  /* 0x7634 */
#define DP2_AMR_DL_ACS_23                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0006))                  /* 0x7636 */
#define DP2_AMR_UL_ACS_01                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0007))                  /* 0x7638 */
#define DP2_AMR_UL_ACS_23                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0008))                  /* 0x763A */
#define DP2_AMR_CONFIG_FLAGS                (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0009))                  /* 0x763C */
#define DP2_AMR_CI_COMPEN                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x000A))                  /* 0x763E */

#define DP2_VAMOS_AMR_BFI_SAIC_TH_BASE      (DP2_AMR_CTRL_BASE + 0x000B)                                                    /* 0x7640 */

#define DP2_VAMOS_AMR_BFI_SAIC_TH           (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0000))     /* 0x7640 */
#define DP2_VAMOS_AMR_BFI_M_DTX_SAIC_0      (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0000))     /* 0x7640 */
#define DP2_VAMOS_BFI_MODEM_0_SAIC          (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0000))     /* 0x7640 */
#define DP2_VAMOS_AMR_BFI_M_DTX_SAIC_1      (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0001))     /* 0x7642 */
#define DP2_VAMOS_BFI_MODEM_1_SAIC          (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0001))     /* 0x7642 */
#define DP2_VAMOS_AMR_BFI_M_DTX_SAIC_2      (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0002))     /* 0x7644 */
#define DP2_VAMOS_BFI_SPEECH_0_SAIC         (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0002))     /* 0x7644 */
#define DP2_VAMOS_AMR_BFI_M_DTX_SAIC_3      (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0003))     /* 0x7646 */
#define DP2_VAMOS_BFI_SPEECH_1_SAIC         (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0003))     /* 0x7646 */
#define DP2_VAMOS_AMR_BFI_M_ACTIVE_SAIC_0   (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0004))     /* 0x7648 */
#define DP2_VAMOS_BFI_UFI_SAIC              (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0004))     /* 0x7648 */
#define DP2_VAMOS_AMR_BFI_M_ACTIVE_SAIC_1   (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0005))     /* 0x764A */
#define DP2_VAMOS_AMR_BFI_M_ACTIVE_SAIC_2   (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0006))     /* 0x764C */
#define DP2_VAMOS_AMR_BFI_M_ACTIVE_SAIC_3   (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0007))     /* 0x764E */
#define DP2_VAMOS_AMR_BFI_SP_0_SAIC_0       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0008))     /* 0x7650 */
#define DP2_VAMOS_AMR_BFI_SP_0_SAIC_1       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0009))     /* 0x7652 */
#define DP2_VAMOS_AMR_BFI_SP_0_SAIC_2       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000A))     /* 0x7654 */
#define DP2_VAMOS_AMR_BFI_SP_0_SAIC_3       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000B))     /* 0x7656 */
#define DP2_VAMOS_AMR_BFI_SP_1_SAIC_0       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000C))     /* 0x7658 */
#define DP2_VAMOS_AMR_BFI_SP_1_SAIC_1       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000D))     /* 0x765A */
#define DP2_VAMOS_AMR_BFI_SP_1_SAIC_2       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000E))     /* 0x765C */
#define DP2_VAMOS_AMR_BFI_SP_1_SAIC_3       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000F))     /* 0x765E */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_0       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0010))     /* 0x7660 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_1       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0011))     /* 0x7662 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_2       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0012))     /* 0x7664 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_3       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0013))     /* 0x7666 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_X       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0014))     /* 0x7668 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_Y       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0015))     /* 0x766A */

#define DP2_AMR_BFI_SAIC_TH_BASE            (DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0016)                                       /* 0x766C */

#define DP2_AMR_BFI_SAIC_TH                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0000))           /* 0x766C */
#define DP2_AMR_BFI_M_DTX_SAIC_0            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0000))           /* 0x766C */
#define DP2_BFI_MODEM_0_SAIC                (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0000))           /* 0x766C */
#define DP2_AMR_BFI_M_DTX_SAIC_1            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0001))           /* 0x766E */
#define DP2_BFI_MODEM_1_SAIC                (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0001))           /* 0x766E */
#define DP2_AMR_BFI_M_DTX_SAIC_2            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0002))           /* 0x7670 */
#define DP2_BFI_SPEECH_0_SAIC               (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0002))           /* 0x7670 */
#define DP2_AMR_BFI_M_DTX_SAIC_3            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0003))           /* 0x7672 */
#define DP2_BFI_SPEECH_1_SAIC               (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0003))           /* 0x7672 */
#define DP2_AMR_BFI_M_ACTIVE_SAIC_0         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0004))           /* 0x7674 */
#define DP2_BFI_UFI_SAIC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0004))           /* 0x7674 */
#define DP2_AMR_BFI_M_ACTIVE_SAIC_1         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0005))           /* 0x7676 */
#define DP2_BFI_MODEM_0                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0005))           /* 0x7676 */
#define DP2_AMR_BFI_M_ACTIVE_SAIC_2         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0006))           /* 0x7678 */
#define DP2_BFI_MODEM_1                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0006))           /* 0x7678 */
#define DP2_AMR_BFI_M_ACTIVE_SAIC_3         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0007))           /* 0x767A */
#define DP2_BFI_SPEECH_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0007))           /* 0x767A */
#define DP2_AMR_BFI_SP_0_SAIC_0             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0008))           /* 0x767C */
#define DP2_BFI_SPEECH_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0008))           /* 0x767C */
#define DP2_AMR_BFI_SP_0_SAIC_1             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0009))           /* 0x767E */
#define DP2_BFI_UFI                         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0009))           /* 0x767E */
#define DP2_AMR_BFI_SP_0_SAIC_2             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000A))           /* 0x7680 */
#define DP2_AMR_BFI_SP_0_SAIC_3             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000B))           /* 0x7682 */
#define DP2_AMR_BFI_SP_1_SAIC_0             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000C))           /* 0x7684 */
#define DP2_AMR_BFI_SP_1_SAIC_1             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000D))           /* 0x7686 */
#define DP2_AMR_BFI_SP_1_SAIC_2             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000E))           /* 0x7688 */
#define DP2_AMR_BFI_SP_1_SAIC_3             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000F))           /* 0x768A */
#define DP2_AMR_BFI_SP_2_SAIC_0             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0010))           /* 0x768C */
#define DP2_AMR_BFI_SP_2_SAIC_1             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0011))           /* 0x768E */
#define DP2_AMR_BFI_SP_2_SAIC_2             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0012))           /* 0x7690 */
#define DP2_AMR_BFI_SP_2_SAIC_3             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0013))           /* 0x7692 */
#define DP2_AMR_BFI_SP_2_SAIC_X             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0014))           /* 0x7694 */
#define DP2_AMR_BFI_SP_2_SAIC_Y             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0015))           /* 0x7696 */

#define DP2_AMR_THRE_BASE                   (DP2_AMR_BFI_SAIC_TH_BASE + 0x0016)                                             /* 0x7698 */

#define DP2_AMR_SP_DEGRADE_THRES_0          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_THRE_BASE + 0x0000))                  /* 0x7698 */
#define DP2_AMR_SP_DEGRADE_THRES_1          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_THRE_BASE + 0x0001))                  /* 0x769A */
#define DP2_AMR_SP_DEGRADE_THRES_2          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_THRE_BASE + 0x0002))                  /* 0x769C */
#define DP2_AMR_SP_DEGRADE_THRES_3          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_THRE_BASE + 0x0003))                  /* 0x769E */

#define DP_MODEM_CTRL_RESERVED_BASE         (DP2_AMR_THRE_BASE + 0x0004)                                                    /* 0x76A0 */

#define DP_LOW_ANT_PWR_TH                   (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0000))        /* 0x76A0 */
#define DP_HEADROOM_DET_TH                  (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0001))        /* 0x76A2 */
#define DP_GAIN_IMB_IDX                     (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0002))        /* 0x76A4 */
#define DP_OBB_WEIGHT                       (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0003))        /* 0x76A6 */
#define DP_OT_TX_IQMM_ARTIFICIAL_DC         (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0004))        /* 0x76A8 */
#define DP_OT_TX_IQMM_GAIN                  (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0005))        /* 0x76AA */
#define DP_OT_TX_IQMM_PHASE                 (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0006))        /* 0x76AC */

#define DP2_ENCRYPT2_BASE                   (DP_MODEM_CTRL_RESERVED_BASE + 0x0013)                                          /* 0x76C6 */

#define DP2_ENCRYP_KEY_5                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPT2_BASE + 0x0000))                  /* 0x76C6 */
#define DP2_ENCRYP_KEY_6                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPT2_BASE + 0x0001))                  /* 0x76C8 */
#define DP2_ENCRYP_KEY_7                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPT2_BASE + 0x0002))                  /* 0x76CA */
#define DP2_ENCRYP_KEY_8                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPT2_BASE + 0x0003))                  /* 0x76CC */

#define DP2_AMR_TRACE_BASE                  (DP2_ENCRYPT2_BASE + 0x0004)                                                    /* 0x76CE */

#define DP2_AMR_USED_CODEC                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0000))                 /* 0x76CE */
#define DP2_AMR_TRACE_CODEC                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0001))                 /* 0x76D0 */
#define DP2_AMR_TRACE_CC_TX                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0002))                 /* 0x76D2 */
#define DP2_AMR_INB_CORR0                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0003))                 /* 0x76D4 */
#define DP2_AMR_RX_TRACE_01_BASE            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0003))                 /* 0x76D4 */
#define DP2_AMR_INB_CORR1                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0004))                 /* 0x76D6 */
#define DP2_AMR_INB_CORR2                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0005))                 /* 0x76D8 */
#define DP2_AMR_INB_CORR3                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0006))                 /* 0x76DA */
#define DP2_AMR_SLRESETFLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0007))                 /* 0x76DC */
#define DP2_AMR_SP_SC                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0008))                 /* 0x76DE */
#define DP2_AMR_SP_SD                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0009))                 /* 0x76E0 */
#define DP2_AMR_EQ_SN_SUM                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x000A))                 /* 0x76E2 */

#define DP_REPORT_BASE                      (DP2_AMR_TRACE_BASE + 0x000B)                                                   /* 0x76E4 */

#define DP_DARP_FOE_Q                       (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0000))                     /* 0x76E0 */
#define DP_EQ_SINR_FWBW_REPLACE_HIT         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0001))                     /* 0x76E6 */
#define DP_EQSO_SUM_LO                      (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0002))                     /* 0x76E8 */
#define DP_EQSO_SUM_HI                      (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0003))                     /* 0x76EA */
#define DP_CHL_S0                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0004))                     /* 0x76EC */
#define DP_CHL_S1                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0005))                     /* 0x76EE */
#define DP_CHL_S2                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0006))                     /* 0x76F0 */
#define DP_CHL_S3                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0007))                     /* 0x76F2 */
#define DP_CHL_S4                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0008))                     /* 0x76F4 */
#define DP_CHL_R_S0                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0009))                     /* 0x76F6 */
#define DP_CHL_R_S1                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x000A))                     /* 0x76F8 */
#define DP_CHL_R_S2                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x000B))                     /* 0x76FA */
#define DP_CHL_R_S3                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x000C))                     /* 0x76FC */
#define DP_CHL_R_S4                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x000D))                     /* 0x76FE */

#define DP_NB_RESULT_RX0_BASE               (DP_REPORT_BASE + 0x0010)                                                       /* 0x7704 */

#define DP_NB_RES_S0_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0000))              /* 0x7704 */
#define DP_TX_IQMM_D_I_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0000))              /* 0x7704 */
#define DP_NB_RES_S0_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0001))              /* 0x7706 */
#define DP_TX_IQMM_D_Q_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0001))              /* 0x7706 */
#define DP_NB_RES_S0_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0002))              /* 0x7708 */
#define DP_TX_IQMM_V_I_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0002))              /* 0x7708 */
#define DP_NB_RES_S0_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0003))              /* 0x770A */
#define DP_TX_IQMM_V_Q_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0003))              /* 0x770A */
#define DP_NB_RES_S0_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0004))              /* 0x770C */
#define DP_TX_IQMM_L_I_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0004))              /* 0x770C */
#define DP_NB_RES_S0_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0005))              /* 0x770E */
#define DP_TX_IQMM_L_Q_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0005))              /* 0x770E */
#define DP_NB_RES_S0_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0006))              /* 0x7710 */
#define DP_NB_RES_S0_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0007))              /* 0x7712 */
#define DP_NB_RES_S0_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0008))              /* 0x7714 */
#define DP_DC_PROC_OUT0                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0008))              /* 0x7714 */
#define DP_NB_RES_S0_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0009))              /* 0x7716 */
#define DP_DC_PROC_OUT1                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0009))              /* 0x7716 */
#define DP_NB_RES_S0_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000A))              /* 0x7718 */
#define DP_DC_PROC_OUT2                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000A))              /* 0x7718 */
#define DP_NB_RES_S0_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000B))              /* 0x772A */
#define DP_NB_RES_S0_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000C))              /* 0x771C */
#define DP_NB_RES_S0_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000D))              /* 0x771E */
#define DP_NB_RES_S0_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000E))              /* 0x7720 */
#define DP_NB_RES_S0_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000F))              /* 0x7722 */
#define DP_NB_RES_S0_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0010))              /* 0x7724 */
#define DP_NB_RES_S0_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0011))              /* 0x7726 */
#define DP_NB_RES_S0_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0012))              /* 0x7728 */
#define DP_NB_RES_S0_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0013))              /* 0x772A */
#define DP_NB_RES_S0_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0014))              /* 0x772C */
#define DP_NB_RES_S0_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0015))              /* 0x772E */
#define DP_NB_RES_S0_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0016))              /* 0x7730 */
#define DP_NB_RES_S0_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0017))              /* 0x7732 */
#define DP_NB_RES_S0_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0018))              /* 0x7734 */
#define DP_NB_RES_S0_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0019))              /* 0x7736 */
#define DP_NB_RES_S0_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001A))              /* 0x7738 */
#define DP_NB_RES_S0_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001B))              /* 0x773A */
#define DP_NB_RES_S0_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001C))              /* 0x773C */
#define DP_NB_RES_S0_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001D))              /* 0x773E */
#define DP_S0_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001D))              /* 0x773E */
#define DP_ENH_MEASURE_REPORT_BASE          (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001D))              /* 0x773E */
#define DP_NB_RES_S0_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001E))              /* 0x7740 */
#define DP_S0_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001E))              /* 0x7740 */

#define DP_NB_RESULT_RX1_BASE               (DP_NB_RESULT_RX0_BASE + 0x0021)                                                /* 0x7746 */

#define DP_NB_RES_S1_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0000))              /* 0x7746 */
#define DP_TX_IQMM_D_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0000))              /* 0x7746 */
#define DP_NB_RES_S1_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0001))              /* 0x7748 */
#define DP_TX_IQMM_D_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0001))              /* 0x7748 */
#define DP_NB_RES_S1_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0002))              /* 0x774A */
#define DP_TX_IQMM_V_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0002))              /* 0x774A */
#define DP_NB_RES_S1_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0003))              /* 0x774C */
#define DP_TX_IQMM_V_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0003))              /* 0x774C */
#define DP_NB_RES_S1_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0004))              /* 0x774E */
#define DP_TX_IQMM_L_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0004))              /* 0x774E */
#define DP_NB_RES_S1_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0005))              /* 0x7750 */
#define DP_TX_IQMM_L_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0005))              /* 0x7750 */
#define DP_NB_RES_S1_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0006))              /* 0x7752 */
#define DP_TX_IQMM_T_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0006))              /* 0x7752 */
#define DP_NB_RES_S1_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0007))              /* 0x7754 */
#define DP_TX_IQMM_T_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0007))              /* 0x7754 */
#define DP_NB_RES_S1_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0008))              /* 0x7756 */
#define DP_TX_IQMM_GT_S1                    (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0008))              /* 0x7756 */
#define DP_NB_RES_S1_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0009))              /* 0x7758 */
#define DP_TX_IQMM_PHIT_S1                  (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0009))              /* 0x7758 */
#define DP_NB_RES_S1_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000A))              /* 0x775A */
#define DP_TX_IQMM_G_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000A))              /* 0x775A */
#define DP_NB_RES_S1_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000B))              /* 0x775C */
#define DP_TX_IQMM_G_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000B))              /* 0x775C */
#define DP_NB_RES_S1_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000C))              /* 0x775E */
#define DP_TX_IQMM_DC_I_S1                  (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000C))              /* 0x775E */
#define DP_NB_RES_S1_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000D))              /* 0x7760 */
#define DP_TX_IQMM_DC_Q_S1                  (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000D))              /* 0x7760 */
#define DP_NB_RES_S1_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000E))              /* 0x7762 */
#define DP_NB_RES_S1_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000F))              /* 0x7764 */
#define DP_NB_RES_S1_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0010))              /* 0x7766 */
#define DP_NB_RES_S1_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0011))              /* 0x7768 */
#define DP_NB_RES_S1_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0012))              /* 0x776A */
#define DP_NB_RES_S1_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0013))              /* 0x776C */
#define DP_NB_RES_S1_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0014))              /* 0x776E */
#define DP_NB_RES_S1_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0015))              /* 0x7770 */
#define DP_NB_RES_S1_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0016))              /* 0x7772 */
#define DP_NB_RES_S1_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0017))              /* 0x7774 */
#define DP_NB_RES_S1_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0018))              /* 0x7776 */
#define DP_NB_RES_S1_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0019))              /* 0x7778 */
#define DP_NB_RES_S1_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001A))              /* 0x777A */
#define DP_NB_RES_S1_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001B))              /* 0x777C */
#define DP_NB_RES_S1_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001C))              /* 0x777E */
#define DP_NB_RES_S1_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001D))              /* 0x7780 */
#define DP_S1_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001D))              /* 0x7780 */
#define DP_NB_RES_S1_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001E))              /* 0x7782 */
#define DP_S1_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001E))              /* 0x7782 */

#define DP_NB_RESULT_RX2_BASE               (DP_NB_RESULT_RX1_BASE + 0x0021)                                                /* 0x7788 */

#define DP_NB_RES_S2_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0000))              /* 0x7788 */
#define DP_NB_RES_S2_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0001))              /* 0x778A */
#define DP_NB_RES_S2_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0002))              /* 0x778C */
#define DP_NB_RES_S2_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0003))              /* 0x778E */
#define DP_NB_RES_S2_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0004))              /* 0x7790 */
#define DP_NB_RES_S2_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0005))              /* 0x7792 */
#define DP_NB_RES_S2_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0006))              /* 0x7794 */
#define DP_NB_RES_S2_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0007))              /* 0x7796 */
#define DP_NB_RES_S2_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0008))              /* 0x7798 */
#define DP_NB_RES_S2_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0009))              /* 0x779A */
#define DP_NB_RES_S2_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000A))              /* 0x779C */
#define DP_NB_RES_S2_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000B))              /* 0x779E */
#define DP_NB_RES_S2_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000C))              /* 0x77A0 */
#define DP_NB_RES_S2_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000D))              /* 0x77A2 */
#define DP_NB_RES_S2_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000E))              /* 0x77A4 */
#define DP_NB_RES_S2_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000F))              /* 0x77A6 */
#define DP_NB_RES_S2_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0010))              /* 0x77A8 */
#define DP_NB_RES_S2_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0011))              /* 0x77AA */
#define DP_NB_RES_S2_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0012))              /* 0x77AC */
#define DP_NB_RES_S2_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0013))              /* 0x77AE */
#define DP_NB_RES_S2_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0014))              /* 0x77B0 */
#define DP_NB_RES_S2_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0015))              /* 0x77B2 */
#define DP_NB_RES_S2_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0016))              /* 0x77B4 */
#define DP_NB_RES_S2_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0017))              /* 0x77B6 */
#define DP_NB_RES_S2_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0018))              /* 0x77B8 */
#define DP_NB_RES_S2_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0019))              /* 0x77BA */
#define DP_NB_RES_S2_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001A))              /* 0x77BC */
#define DP_NB_RES_S2_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001B))              /* 0x77BE */
#define DP_NB_RES_S2_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001C))              /* 0x77C0 */
#define DP_NB_RES_S2_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001D))              /* 0x77C2 */
#define DP_S2_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001D))              /* 0x77C4 */
#define DP_NB_RES_S2_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001E))              /* 0x77C6 */
#define DP_S2_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001E))              /* 0x77C8 */

#define DP_NB_RESULT_RX3_BASE               (DP_NB_RESULT_RX2_BASE + 0x0021)                                                /* 0x77CA */

#define DP_NB_RES_S3_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0000))              /* 0x77CA */
#define DP_NB_RES_S3_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0001))              /* 0x77CC */
#define DP_NB_RES_S3_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0002))              /* 0x77CE */
#define DP_NB_RES_S3_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0003))              /* 0x77D0 */
#define DP_NB_RES_S3_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0004))              /* 0x77D2 */
#define DP_NB_RES_S3_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0005))              /* 0x77D4 */
#define DP_NB_RES_S3_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0006))              /* 0x77D6 */
#define DP_NB_RES_S3_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0007))              /* 0x77D8 */
#define DP_NB_RES_S3_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0008))              /* 0x77DA */
#define DP_NB_RES_S3_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0009))              /* 0x77DC */
#define DP_NB_RES_S3_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000A))              /* 0x77DE */
#define DP_NB_RES_S3_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000B))              /* 0x77E0 */
#define DP_NB_RES_S3_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000C))              /* 0x77E2 */
#define DP_NB_RES_S3_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000D))              /* 0x77E4 */
#define DP_NB_RES_S3_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000E))              /* 0x77E6 */
#define DP_NB_RES_S3_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000F))              /* 0x77E8 */
#define DP_NB_RES_S3_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0010))              /* 0x77EA */
#define DP_NB_RES_S3_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0011))              /* 0x77EC */
#define DP_NB_RES_S3_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0012))              /* 0x77EE */
#define DP_NB_RES_S3_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0013))              /* 0x77F0 */
#define DP_NB_RES_S3_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0014))              /* 0x77F2 */
#define DP_NB_RES_S3_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0015))              /* 0x77F4 */
#define DP_NB_RES_S3_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0016))              /* 0x77F6 */
#define DP_NB_RES_S3_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0017))              /* 0x77F8 */
#define DP_NB_RES_S3_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0018))              /* 0x77FA */
#define DP_NB_RES_S3_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0019))              /* 0x77FC */
#define DP_NB_RES_S3_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001A))              /* 0x77FE */
#define DP_NB_RES_S3_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001B))              /* 0x7800 */
#define DP_NB_RES_S3_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001C))              /* 0x7802 */
#define DP_NB_RES_S3_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001D))              /* 0x7804 */
#define DP_S3_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001D))              /* 0x7804 */
#define DP_NB_RES_S3_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001E))              /* 0x7806 */
#define DP_S3_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001E))              /* 0x7806 */

#define DP_NB_RESULT_RX4_BASE               (DP_NB_RESULT_RX3_BASE + 0x0021)                                                /* 0x780C */

#define DP_NB_RES_S4_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0000))              /* 0x780C */
#define DP_NB_RES_S4_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0001))              /* 0x780E */
#define DP_NB_RES_S4_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0002))              /* 0x7810 */
#define DP_NB_RES_S4_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0003))              /* 0x7812 */
#define DP_NB_RES_S4_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0004))              /* 0x7814 */
#define DP_NB_RES_S4_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0005))              /* 0x7816 */
#define DP_NB_RES_S4_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0006))              /* 0x7818 */
#define DP_NB_RES_S4_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0007))              /* 0x781A */
#define DP_NB_RES_S4_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0008))              /* 0x781C */
#define DP_NB_RES_S4_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0009))              /* 0x781E */
#define DP_NB_RES_S4_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000A))              /* 0x7820 */
#define DP_NB_RES_S4_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000B))              /* 0x7822 */
#define DP_NB_RES_S4_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000C))              /* 0x7824 */
#define DP_NB_RES_S4_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000D))              /* 0x7826 */
#define DP_NB_RES_S4_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000E))              /* 0x7828 */
#define DP_NB_RES_S4_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000F))              /* 0x782A */
#define DP_NB_RES_S4_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0010))              /* 0x782C */
#define DP_NB_RES_S4_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0011))              /* 0x782E */
#define DP_NB_RES_S4_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0012))              /* 0x7830 */
#define DP_NB_RES_S4_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0013))              /* 0x7832 */
#define DP_NB_RES_S4_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0014))              /* 0x7834 */
#define DP_NB_RES_S4_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0015))              /* 0x7836 */
#define DP_NB_RES_S4_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0016))              /* 0x7838 */
#define DP_NB_RES_S4_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0017))              /* 0x783A */
#define DP_NB_RES_S4_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0018))              /* 0x783C */
#define DP_NB_RES_S4_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0019))              /* 0x783E */
#define DP_NB_RES_S4_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001A))              /* 0x7840 */
#define DP_NB_RES_S4_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001B))              /* 0x7842 */
#define DP_NB_RES_S4_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001C))              /* 0x7844 */
#define DP_NB_RES_S4_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001D))              /* 0x7846 */
#define DP_S4_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001D))              /* 0x7848 */
#define DP_NB_RES_S4_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001E))              /* 0x784A */
#define DP_S4_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001E))              /* 0x784C */

#define DP_NB_RESULT_RX5_BASE               (DP_NB_RESULT_RX4_BASE + 0x0021)                                                /* 0x784E */

#define DP_NB_RES_S5_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0000))              /* 0x784E */
#define DP_NB_RES_S5_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0001))              /* 0x7850 */
#define DP_NB_RES_S5_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0002))              /* 0x7852 */
#define DP_NB_RES_S5_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0003))              /* 0x7854 */
#define DP_NB_RES_S5_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0004))              /* 0x7856 */
#define DP_NB_RES_S5_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0005))              /* 0x7858 */
#define DP_NB_RES_S5_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0006))              /* 0x785A */
#define DP_NB_RES_S5_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0007))              /* 0x785C */

#define DP_NB_RESULT_RX6_BASE               (DP_NB_RESULT_RX5_BASE + 0x0008)                                                /* 0x785E */

#define DP_NB_RES_S6_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0000))              /* 0x785E */
#define DP_NB_RES_S6_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0001))              /* 0x7860 */
#define DP_NB_RES_S6_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0002))              /* 0x7862 */
#define DP_NB_RES_S6_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0003))              /* 0x7864 */
#define DP_NB_RES_S6_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0004))              /* 0x7866 */
#define DP_NB_RES_S6_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0005))              /* 0x7868 */
#define DP_NB_RES_S6_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0006))              /* 0x786A */
#define DP_NB_RES_S6_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0007))              /* 0x786C */

#define DP_NB_RESULT_RX7_BASE               (DP_NB_RESULT_RX6_BASE + 0x0008)                                                /* 0x786E */

#define DP_NB_RES_S7_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0000))              /* 0x786E */
#define DP_NB_RES_S7_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0001))              /* 0x7870 */
#define DP_NB_RES_S7_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0002))              /* 0x7872 */
#define DP_NB_RES_S7_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0003))              /* 0x7874 */
#define DP_NB_RES_S7_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0004))              /* 0x7876 */
#define DP_NB_RES_S7_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0005))              /* 0x7878 */
#define DP_NB_RES_S7_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0006))              /* 0x787A */
#define DP_NB_RES_S7_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0007))              /* 0x787C */

#define DP_SB_RESULT_BASE                   (DP_NB_RESULT_RX7_BASE + 0x0008)                                                /* 0x787E */

#define DP_SB_RES_0                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0000))                  /* 0x787E */
#define DP_SB_RES_1                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0001))                  /* 0x7880 */
#define DP_SB_RES_2                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0002))                  /* 0x7882 */
#define DP_SB_RES_3                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0003))                  /* 0x7884 */
#define DP_SB_RES_4                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0004))                  /* 0x7886 */
#define DP_SB_RES_5                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0005))                  /* 0x7888 */
#define DP_SB_RES_6                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0006))                  /* 0x788A */
#define DP_SB_RES_7                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0007))                  /* 0x788C */
#define DP_SB_RES_8                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0008))                  /* 0x788E */
#define DP_SB_RES_9                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0009))                  /* 0x7890 */
#define DP_SB_RES_10                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000A))                  /* 0x7892 */
#define DP_SB_RES_11                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000B))                  /* 0x7894 */
#define DP_SB_RES_12                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000C))                  /* 0x7896 */
#define DP_SB_RES_13                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000D))                  /* 0x7898 */
#define DP_SB_RES_14                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000E))                  /* 0x789A */
#define DP_SB_RES_15                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000F))                  /* 0x789C */

#define DP_FB_RESULT_BASE                   (DP_SB_RESULT_BASE + 0x0011)                                                    /* 0x789E */

#define DP_FB_RES_0                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0000))                  /* 0x78A0 */
#define DP_FB_RES_1                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0001))                  /* 0x78A2 */
#define DP_FB_RES_2                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0002))                  /* 0x78A4 */
#define DP_FB_RES_3                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0003))                  /* 0x78A6 */
#define DP_FB_RES_4                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0004))                  /* 0x78A8 */
#define DP_FB_RES_5                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0005))                  /* 0x78AA */
#define DP_FB_RES_6                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0006))                  /* 0x78AC */
#define DP_FB_RES_7                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0007))                  /* 0x78AE */
#define DP_FB_RES_8                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0008))                  /* 0x78B0 */
#define DP_FB_RES_9                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0009))                  /* 0x78B2 */
#define DP_FB_RES_10                        (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x000A))                  /* 0x78B4 */
#define DP_FB_RES_11                        (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x000B))                  /* 0x78B6 */
#define DP_FB_RES_12                        (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x000C))                  /* 0x78B8 */
#define DP_FB_RES_13                        (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x000D))                  /* 0x78BA */

#define DP2_FAST_USF_REPORT_BASE            (DP_FB_RESULT_BASE + 0x0010)                                                    /* 0x78C0 */

#define DP2_CC_USF_S0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0000))           /* 0x78C0 */
#define DP_SF_VALUE                         (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0000))           /* 0x78C0 */
#define DP2_CC_USF_S1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0001))           /* 0x78C2 */
#define DP2_AMR_BFI_TH_BASE                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0001))           /* 0x78C2 */
#define DP2_AMR_BFI_M_DTX_0                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0001))           /* 0x78C2 */
#define DP2_CC_USF_S2                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0002))           /* 0x78C4 */
#define DP2_AMR_BFI_M_DTX_1                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0002))           /* 0x78C4 */
#define DP2_CC_USF_S3                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0003))           /* 0x78C6 */
#define DP2_AMR_BFI_M_DTX_2                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0003))           /* 0x78C6 */
#define DP2_CC_USF_S4                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0004))           /* 0x78C8 */
#define DP2_AMR_BFI_M_DTX_3                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0004))           /* 0x78C8 */
#define DP2_CC_USF2_S0                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0005))           /* 0x78CA */
#define DP2_AMR_BFI_M_ACTIVE_0              (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0005))           /* 0x78CA */
#define DP2_CC_USF2_S1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0006))           /* 0x78CC */
#define DP2_AMR_BFI_M_ACTIVE_1              (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0006))           /* 0x78CC */
#define DP2_CC_USF2_S2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0007))           /* 0x78CE */
#define DP2_AMR_BFI_M_ACTIVE_2              (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0007))           /* 0x78CE */
#define DP2_CC_USF2_S3                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0008))           /* 0x78D0 */
#define DP2_AMR_BFI_M_ACTIVE_3              (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0008))           /* 0x78D0 */
#define DP2_CC_USF2_S4                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0009))           /* 0x78D2 */
#define DP2_AMR_BFI_SP_0_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0009))           /* 0x78D2 */
#define DP2_CC_PRE_USF_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000A))           /* 0x78D4 */
#define DP2_AMR_BFI_SP_0_1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000A))           /* 0x78D4 */
#define DP2_CC_PRE_USF_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000B))           /* 0x78D6 */
#define DP2_AMR_BFI_SP_0_2                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000B))           /* 0x78D6 */
#define DP2_CC_PRE_USF_S2                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000C))           /* 0x78D8 */
#define DP2_AMR_BFI_SP_0_3                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000C))           /* 0x78D8 */
#define DP2_CC_PRE_USF_S3                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000D))           /* 0x78DA */
#define DP2_AMR_BFI_SP_1_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000D))           /* 0x78DA */
#define DP2_CC_PRE_USF_S4                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000E))           /* 0x78DC */
#define DP2_AMR_BFI_SP_1_1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000E))           /* 0x78DC */
#define DP2_CC_PRE_USF2_S0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000F))           /* 0x78DE */
#define DP2_AMR_BFI_SP_1_2                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000F))           /* 0x78DE */
#define DP2_CC_PRE_USF2_S1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0010))           /* 0x78E0 */
#define DP2_AMR_BFI_SP_1_3                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0010))           /* 0x78E0 */
#define DP2_CC_PRE_USF2_S2                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0011))           /* 0x78E2 */
#define DP2_AMR_BFI_SP_2_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0011))           /* 0x78E2 */
#define DP2_CC_PRE_USF2_S3                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0012))           /* 0x78E4 */
#define DP2_AMR_BFI_SP_2_1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0012))           /* 0x78E4 */
#define DP2_CC_PRE_USF2_S4                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0013))           /* 0x78E6 */
#define DP2_AMR_BFI_SP_2_2                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0013))           /* 0x78E6 */
#define DP2_CC_CS_USF_S0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0014))           /* 0x78E8 */
#define DP2_AMR_BFI_SP_2_3                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0014))           /* 0x78E8 */
#define DP2_CC_CS_USF_S1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0015))           /* 0x78EA */
#define DP2_AMR_BFI_SP_2_X                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0015))           /* 0x78EA */
#define DP2_CC_CS_USF_S2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0016))           /* 0x78EC */
#define DP2_AMR_BFI_SP_2_Y                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0016))           /* 0x78EC */
#define DP2_CC_CS_USF_S3                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0017))           /* 0x78EE */
#define DP2_CC_CS_USF_S4                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0018))           /* 0x78F0 */
#define DP2_CC_CS_PRE_USF_S0                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0019))           /* 0x78F2 */
#define DP2_CC_CS_PRE_USF_S1                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x001A))           /* 0x78F4 */
#define DP2_CC_CS_PRE_USF_S2                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x001B))           /* 0x78F6 */
#define DP2_CC_CS_PRE_USF_S3                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x001C))           /* 0x78F8 */
#define DP2_CC_CS_PRE_USF_S4                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x001D))           /* 0x78FA */

#define DP2_TX_CCCH_BASE                    (DP2_FAST_USF_REPORT_BASE + 0x001E)                                             /* 0x78FC */

#define DP2_TX_CCCH_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0000))                   /* 0x78FC */
#define DP2_TX_CCCH_1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0001))                   /* 0x78FE */
#define DP2_TX_CCCH_2                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0002))                   /* 0x7900 */
#define DP2_TX_CCCH_3                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0003))                   /* 0x7902 */
#define DP2_TX_CCCH_4                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0004))                   /* 0x7904 */
#define DP2_TX_CCCH_5                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0005))                   /* 0x7906 */
#define DP2_TX_CCCH_6                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0006))                   /* 0x7908 */
#define DP2_TX_CCCH_7                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0007))                   /* 0x790A */
#define DP2_TX_CCCH_8                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0008))                   /* 0x790C */
#define DP2_TX_CCCH_9                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0009))                   /* 0x790E */
#define DP2_TX_CCCH_10                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x000A))                   /* 0x7910 */
#define DP2_TX_CCCH_11                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x000B))                   /* 0x7912 */

#define DP2_TX_FACCH_BASE                   (DP2_TX_CCCH_BASE + 0x000C)                                                     /* 0x7914 */

#define DP2_TX_FACCH_0                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0000))                  /* 0x7914 */
#define DP2_TX_FACCH_1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0001))                  /* 0x7916 */
#define DP2_TX_FACCH_2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0002))                  /* 0x7918 */
#define DP2_TX_FACCH_3                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0003))                  /* 0x791A */
#define DP2_TX_FACCH_4                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0004))                  /* 0x791C */
#define DP2_TX_FACCH_5                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0005))                  /* 0x791E */
#define DP2_TX_FACCH_6                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0006))                  /* 0x7920 */
#define DP2_TX_FACCH_7                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0007))                  /* 0x7922 */
#define DP2_TX_FACCH_8                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0008))                  /* 0x7924 */
#define DP2_TX_FACCH_9                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0009))                  /* 0x7926 */
#define DP2_TX_FACCH_10                     (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x000A))                  /* 0x7928 */
#define DP2_TX_FACCH_11                     (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x000B))                  /* 0x792A */

#define DP2_TX_RACH_BASE                    (DP2_TX_FACCH_BASE + 0x000C)                                                    /* 0x792C */

#define DP2_TX_RACH_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RACH_BASE + 0x0000))                   /* 0x792C */
#define DP2_TX_RACH_1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RACH_BASE + 0x0001))                   /* 0x792E */

#define DP2_TX_RATSCCH_BASE                 (DP2_TX_RACH_BASE + 0x0002)                                                     /* 0x7930 */

#define DP2_TX_RATSCCH_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RATSCCH_BASE + 0x0000))                /* 0x7930 */
#define DP2_TX_RATSCCH_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RATSCCH_BASE + 0x0001))                /* 0x7932 */
#define DP2_TX_RATSCCH_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RATSCCH_BASE + 0x0002))                /* 0x7934 */
#define DP2_TX_RATSCCH_3                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RATSCCH_BASE + 0x0003))                /* 0x7936 */

#define DP2_RX_CCCH_PTCCH0_BASE             (DP2_TX_RATSCCH_BASE + 0x0004)                                                  /* 0x7938 */

#define DP2_RX_PTCCH0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0000))            /* 0x7938 */
#define DP2_RX_CCCH_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0000))            /* 0x7938 */
#define DP2_RX_CCCH_1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0001))            /* 0x793A */
#define DP2_RX_CCCH_2                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0002))            /* 0x793C */
#define DP2_RX_CCCH_3                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0003))            /* 0x793E */
#define DP2_RX_CCCH_4                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0004))            /* 0x7940 */
#define DP2_RX_CCCH_5                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0005))            /* 0x7942 */
#define DP2_RX_CCCH_6                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0006))            /* 0x7944 */
#define DP2_RX_CCCH_7                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0007))            /* 0x7946 */
#define DP2_RX_CCCH_8                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0008))            /* 0x7948 */
#define DP2_RX_CCCH_9                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0009))            /* 0x794A */
#define DP2_RX_CCCH_10                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x000A))            /* 0x794C */
#define DP2_RX_CCCH_11                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x000B))            /* 0x794E */
#define DP2_RX_CCCH_12                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x000C))            /* 0x7950 */

#define DP2_RX_FACCH_PTCCH1_BASE            (DP2_RX_CCCH_PTCCH0_BASE + 0x000D)                                              /* 0x7952 */

#define DP2_RX_PTCCH1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0000))           /* 0x7952 */
#define DP2_RX_FACCH_0                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0000))           /* 0x7952 */
#define DP2_RX_FACCH_1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0001))           /* 0x7954 */
#define DP2_RX_FACCH_2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0002))           /* 0x7956 */
#define DP2_RX_FACCH_3                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0003))           /* 0x7958 */
#define DP2_RX_FACCH_4                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0004))           /* 0x795A */
#define DP2_RX_FACCH_5                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0005))           /* 0x795C */
#define DP2_RX_FACCH_6                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0006))           /* 0x795E */
#define DP2_RX_FACCH_7                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0007))           /* 0x7960 */
#define DP2_RX_FACCH_8                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0008))           /* 0x7962 */
#define DP2_RX_FACCH_9                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0009))           /* 0x7964 */
#define DP2_RX_FACCH_10                     (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x000A))           /* 0x7966 */
#define DP2_RX_FACCH_11                     (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x000B))           /* 0x7968 */
#define DP2_RX_FACCH_12                     (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x000C))           /* 0x796A */

#define DP2_RX_SCH_BASE                     (DP2_RX_FACCH_PTCCH1_BASE + 0x000D)                                             /* 0x796C */

#define DP2_RX_SCH_0                        (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_SCH_BASE + 0x0000))                    /* 0x796C */
#define DP2_RX_SCH_1                        (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_SCH_BASE + 0x0001))                    /* 0x796E */
#define DP2_RX_SCH_2                        (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_SCH_BASE + 0x0002))                    /* 0x7970 */
#define DP2_RX_SCH_3                        (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_SCH_BASE + 0x0003))                    /* 0x7972 */

#define DP2_RX_RATSCCH_BASE                 (DP2_RX_SCH_BASE + 0x0004)                                                      /* 0x7974 */

#define DP2_RX_RATSCCH_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_RATSCCH_BASE + 0x0000))                /* 0x7974 */
#define DP2_RX_RATSCCH_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_RATSCCH_BASE + 0x0001))                /* 0x7976 */
#define DP2_RX_RATSCCH_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_RATSCCH_BASE + 0x0002))                /* 0x7978 */
#define DP2_RX_RATSCCH_3                    (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_RATSCCH_BASE + 0x0003))                /* 0x797A */

#define DP_TX_TCH_S0_BASE                   (DP2_RX_RATSCCH_BASE + 0x0004)                                                  /* 0x797C */

#define DP2_TX_TCH_S0_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0000))                  /* 0x797C */
#define DP2_TX_TCH_S0_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0001))                  /* 0x797E */
#define DP2_TX_TCH_S0_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0002))                  /* 0x7980 */
#define DP2_TX_TCH_S0_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0003))                  /* 0x7982 */
#define DP2_TX_TCH_S0_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0004))                  /* 0x7984 */
#define DP2_TX_TCH_S0_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0005))                  /* 0x7986 */
#define DP2_TX_TCH_S0_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0006))                  /* 0x7988 */
#define DP2_TX_TCH_S0_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0007))                  /* 0x798A */

#define DP_TX_TCH_S1_BASE                   (DP_TX_TCH_S0_BASE + 0x0008)                                                    /* 0x798C */

#define DP2_TX_TCH_S1_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0000))                  /* 0x798C */
#define DP2_BFI_QUAL_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0000))                  /* 0x798C */
#define DP2_TX_TCH_S1_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0001))                  /* 0x798E */
#define DP2_BFI_QUAL_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0001))                  /* 0x798E */
#define DP2_TX_TCH_S1_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0002))                  /* 0x7990 */
#define DP2_BFI_QUAL_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0002))                  /* 0x7990 */
#define DP2_TX_TCH_S1_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0003))                  /* 0x7992 */
#define DP2_BFI_QUAL_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0003))                  /* 0x7992 */
#define DP2_TX_TCH_S1_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0004))                  /* 0x7994 */
#define DP2_TX_TCH_S1_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0005))                  /* 0x7996 */
#define DP2_TX_TCH_S1_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0006))                  /* 0x7998 */
#define DP2_TX_TCH_S1_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0007))                  /* 0x799A */

#define DP_TX_TCH_S2_BASE                   (DP_TX_TCH_S1_BASE + 0x0008)                                                    /* 0x799C */

#define DP2_TX_TCH_S2_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0000))                  /* 0x799C */
#define DP2_AMR_RX_TRACE_00_BASE            (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0000))                  /* 0x799C */
#define DP2_AMR_RX_FLOW_FLAG                (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0000))                  /* 0x799C */
#define DP2_TX_TCH_S2_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0001))                  /* 0x799E */
#define DP2_AMR_SV_SD_TYPE                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0001))                  /* 0x799E */
#define DP2_TX_TCH_S2_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0002))                  /* 0x79A0 */
#define DP2_AMR_CONFIG_FLAGS_TRACE          (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0002))                  /* 0x79A0 */
#define DP2_TX_TCH_S2_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0003))                  /* 0x79A2 */
#define DP2_AMR_IM_DEC                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0003))                  /* 0x79A2 */
#define DP2_TX_TCH_S2_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0004))                  /* 0x79A4 */
#define DP2_AMR_T2_CD                       (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0004))                  /* 0x79A4 */
#define DP2_TX_TCH_S2_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0005))                  /* 0x79A6 */
#define DP2_AMR_BFI                         (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0005))                  /* 0x79A6 */
#define DP2_TX_TCH_S2_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0006))                  /* 0x79A8 */
#define DP2_AMR_DL_FACCH                    (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0006))                  /* 0x79A8 */
#define DP2_TX_TCH_S2_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0007))                  /* 0x79AA */
#define DP2_AMR_DL_RATSCCH                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0007))                  /* 0x79AA */

#define DP_TX_TCH_S3_BASE                   (DP_TX_TCH_S2_BASE + 0x0008)                                                    /* 0x79AC */

#define DP2_TX_TCH_S3_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0000))                  /* 0x79AC */
#define DP2_AMR_TX_TRACE_BASE               (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0000))                  /* 0x79AC */
#define DP2_AMR_T2_CE                       (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0000))                  /* 0x79AC */
#define DP2_TX_TCH_S3_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0001))                  /* 0x79AE */
#define DP2_AMR_UL_FACCH                    (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0001))                  /* 0x79AE */
#define DP2_TX_TCH_S3_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0002))                  /* 0x79B0 */
#define DP2_AMR_UL_RATSCCH                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0002))                  /* 0x79B0 */
#define DP2_TX_TCH_S3_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0003))                  /* 0x79B2 */
#define DP2_AMR_S2_SP_FLAG                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0003))                  /* 0x79B2 */
#define DP2_TX_TCH_S3_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0004))                  /* 0x79B4 */
#define DP2_AMR_SID_STOLEN                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0004))                  /* 0x79B4 */
#define DP2_TX_TCH_S3_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0005))                  /* 0x79B6 */
#define DP2_AMR_SV_SC_TYPE                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0005))                  /* 0x79B6 */
#define DP2_TX_TCH_S3_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0006))                  /* 0x79B8 */
#define DP2_AMR_TX_FLOW_FLAG                (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0006))                  /* 0x79B8 */
#define DP2_TX_TCH_S3_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0007))                  /* 0x79BA */

#define DP_TX_TCH_S4_BASE                   (DP_TX_TCH_S3_BASE + 0x0008)                                                    /* 0x79BC */

#define DP2_TX_TCH_S4_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0000))                  /* 0x79BC */
#define DP2_TX_TCH_S4_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0001))                  /* 0x79BE */
#define DP2_TX_TCH_S4_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0002))                  /* 0x79C0 */
#define DP2_TX_TCH_S4_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0003))                  /* 0x79C2 */
#define DP2_TX_TCH_S4_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0004))                  /* 0x79C4 */
#define DP2_TX_TCH_S4_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0005))                  /* 0x79C6 */
#define DP2_TX_TCH_S4_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0006))                  /* 0x79C8 */
#define DP2_TX_TCH_S4_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0007))                  /* 0x79CA */

#define DP_RX_TCH_S0_BASE                   (DP_TX_TCH_S4_BASE + 0x0008)                                                    /* 0x79CC */

#define DP2_RX_TCH_S0_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0000))                  /* 0x79CC */
#define DP2_RX_TCH_S0_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0001))                  /* 0x79CE */
#define DP2_RX_TCH_S0_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0002))                  /* 0x79D0 */
#define DP2_RX_TCH_S0_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0003))                  /* 0x79D2 */
#define DP2_RX_TCH_S0_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0004))                  /* 0x79D4 */
#define DP2_RX_TCH_S0_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0005))                  /* 0x79D6 */
#define DP2_RX_TCH_S0_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0006))                  /* 0x79D8 */
#define DP2_RX_TCH_S0_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0007))                  /* 0x79DA */

#define DP_RX_TCH_S1_BASE                   (DP_RX_TCH_S0_BASE + 0x0008)                                                    /* 0x79DC */

#define DP2_RX_TCH_S1_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0000))                  /* 0x79DC */
#define DP2_RX_TCH_S1_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0001))                  /* 0x79DE */
#define DP2_RX_TCH_S1_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0002))                  /* 0x79E0 */
#define DP2_RX_TCH_S1_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0003))                  /* 0x79E2 */
#define DP2_RX_TCH_S1_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0004))                  /* 0x79E4 */
#define DP2_RX_TCH_S1_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0005))                  /* 0x79E6 */
#define DP2_RX_TCH_S1_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0006))                  /* 0x79E8 */
#define DP2_RX_TCH_S1_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0007))                  /* 0x79EA */

#define DP_RX_TCH_S2_BASE                   (DP_RX_TCH_S1_BASE + 0x0008)                                                    /* 0x79EC */

#define DP2_RX_TCH_S2_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0000))                  /* 0x79EC */
#define DP2_RX_TCH_S2_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0001))                  /* 0x79EE */
#define DP2_RX_TCH_S2_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0002))                  /* 0x79F0 */
#define DP2_RX_TCH_S2_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0003))                  /* 0x79F2 */
#define DP2_RX_TCH_S2_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0004))                  /* 0x79F4 */
#define DP2_RX_TCH_S2_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0005))                  /* 0x79F6 */
#define DP2_RX_TCH_S2_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0006))                  /* 0x79F8 */
#define DP2_RX_TCH_S2_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0007))                  /* 0x79FA */

#define DP_RX_TCH_S3_BASE                   (DP_RX_TCH_S2_BASE + 0x0008)                                                    /* 0x79FC */

#define DP2_RX_TCH_S3_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0000))                  /* 0x79FC */
#define DP2_RX_TCH_S3_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0001))                  /* 0x79FE */
#define DP2_RX_TCH_S3_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0002))                  /* 0x7A00 */
#define DP2_RX_TCH_S3_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0003))                  /* 0x7A02 */
#define DP2_RX_TCH_S3_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0004))                  /* 0x7A04 */
#define DP2_RX_TCH_S3_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0005))                  /* 0x7A06 */
#define DP2_RX_TCH_S3_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0006))                  /* 0x7A08 */
#define DP2_RX_TCH_S3_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0007))                  /* 0x7A0A */

#define DP_RX_TCH_S4_BASE                   (DP_RX_TCH_S3_BASE + 0x0008)                                                    /* 0x7A0C */

#define DP2_RX_TCH_S4_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0000))                  /* 0x7A0C */
#define DP2_RX_TCH_S4_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0001))                  /* 0x7A0E */
#define DP2_RX_TCH_S4_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0002))                  /* 0x7A10 */
#define DP2_RX_TCH_S4_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0003))                  /* 0x7A12 */
#define DP2_RX_TCH_S4_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0004))                  /* 0x7A14 */
#define DP2_RX_TCH_S4_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0005))                  /* 0x7A16 */
#define DP2_RX_TCH_S4_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0006))                  /* 0x7A18 */
#define DP2_RX_TCH_S4_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0007))                  /* 0x7A1A */

#define DP2_TEST_FEATURES_S0_BASE           (DP_RX_TCH_S4_BASE + 0x0008)                                                    /* 0x7A1C */

#define DP2_TX_TEST_S0_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S0_BASE + 0x0000))          /* 0x7A1C */
#define DP2_TX_TEST_S0_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S0_BASE + 0x0001))          /* 0x7A1E */
#define DP2_TX_TEST_S0_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S0_BASE + 0x0002))          /* 0x7A20 */

#define DP2_TEST_FEATURES_S1_BASE           (DP2_TEST_FEATURES_S0_BASE + 0x0003)                                            /* 0x7A22 */

#define DP2_TX_TEST_S1_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S1_BASE + 0x0000))          /* 0x7A22 */
#define DP2_TX_TEST_S1_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S1_BASE + 0x0001))          /* 0x7A24 */
#define DP2_TX_TEST_S1_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S1_BASE + 0x0002))          /* 0x7A26 */

#define DP2_TEST_FEATURES_S2_BASE           (DP2_TEST_FEATURES_S1_BASE + 0x0003)                                            /* 0x7A28 */

#define DP2_TX_TEST_S2_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S2_BASE + 0x0000))          /* 0x7A28 */
#define DP2_TX_TEST_S2_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S2_BASE + 0x0001))          /* 0x7A2A */
#define DP2_TX_TEST_S2_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S2_BASE + 0x0002))          /* 0x7A2C */

#define DP2_TEST_FEATURES_S3_BASE           (DP2_TEST_FEATURES_S2_BASE + 0x0003)                                            /* 0x7A2E */

#define DP2_TX_TEST_S3_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S3_BASE + 0x0000))          /* 0x7A2E */
#define DP2_TX_TEST_S3_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S3_BASE + 0x0001))          /* 0x7A30 */
#define DP2_TX_TEST_S3_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S3_BASE + 0x0002))          /* 0x7A32 */

#define DP2_TEST_FEATURES_S4_BASE           (DP2_TEST_FEATURES_S3_BASE + 0x0003)                                            /* 0x7A34 */

#define DP2_TX_TEST_S4_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S4_BASE + 0x0000))          /* 0x7A34 */
#define DP2_TX_TEST_S4_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S4_BASE + 0x0001))          /* 0x7A36 */
#define DP2_TX_TEST_S4_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S4_BASE + 0x0002))          /* 0x7A38 */

#define DP_OUTER_REPORT_BASE                (DP2_TEST_FEATURES_S4_BASE + 0x0003)                                            /* 0x7A3A */

#define DP2_BFI_USED_THRES                  (*(volatile uint16_t *)DPRAM_BASE(DP_OUTER_REPORT_BASE + 0x0000))               /* 0x7A3A */
#define DP2_BFI_USED_D                      (*(volatile uint16_t *)DPRAM_BASE(DP_OUTER_REPORT_BASE + 0x0001))               /* 0x7A3C */

#define DP_EGPRS_BITMAP_DEBUG_BASE          (DP_OUTER_REPORT_BASE + 0x0002)                                                 /* 0x7A3E */

#define DP_EGPRS_BITMAP_DEBUG_0             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0000))         /* 0x7A3E */
#define DP_EGPRS_BITMAP_DEBUG_1             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0001))         /* 0x7A40 */
#define DP_EGPRS_BITMAP_DEBUG_2             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0002))         /* 0x7A42 */
#define DP_EGPRS_BITMAP_DEBUG_3             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0003))         /* 0x7A44 */
#define DP_EGPRS_BITMAP_DEBUG_4             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0004))         /* 0x7A46 */
#define DP_EGPRS_BITMAP_DEBUG_5             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0005))         /* 0x7A48 */

#define DP_MODEM_RESERVED_BASE              (DP_EGPRS_BITMAP_DEBUG_BASE + 0x0006)                                           /* 0x7A4A */

#define DP_VAMOS_DEBUG_ZETA_EST             (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0000))             /* 0x7A4A */
#define DP_VAMOS_DEBUG_SCORE1               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0001))             /* 0x7A4C */
#define DP_VAMOS_DEBUG_SCORE2               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0002))             /* 0x7A4E */
#define DP_PREV_T2                          (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0003))             /* 0x7A50 */
#define DP_PREV_WIN_PROC_0123               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0004))             /* 0x7A52 */
#define DP_PREV_WIN_PROC_4567               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0005))             /* 0x7A54 */
#define DP_CURR_T2                          (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0006))             /* 0x7A56 */
#define DP_CURR_WIN_PROC_0123               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0007))             /* 0x7A58 */
#define DP_CURR_WIN_PROC_4567               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0008))             /* 0x7A5A */
#define DP_DIS_EGPRS_REPORT                 (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0009))             /* 0x7A5C */

#define DP2_SP_CODEC_CTRL_BASE              (DP_MODEM_RESERVED_BASE + 0x0047)                                               /* 0x7AD8 */

#define DP_SC_ADDR                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0000))             /* 0x7AD8 */
#define DP2_SC_FLAGS                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0000))             /* 0x7AD8 */
#define SPH_COD_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0000))             /* 0x7AD8 */
#define DP2_DEL_PCM_R                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0001))             /* 0x7ADA */
#define SPH_DEL_R                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0001))             /* 0x7ADA */
#define DP2_DEL_PCM_W                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0002))             /* 0x7ADC */
#define SPH_DEL_W                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0002))             /* 0x7ADC */
#define DP_MARGIN_PCM_ADDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0003))             /* 0x7ADE */
#define DP2_MARGIN_PCM_W                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0003))             /* 0x7ADE */
#define SPH_DEL_M                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0003))             /* 0x7ADE */
#define DP2_SC_MODE                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0004))             /* 0x7AE0 */
#define SPH_COD_MODE                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0004))             /* 0x7AE0 */
#define DP2_SC_VAD                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0005))             /* 0x7AE2 */
#define DP2_SC_MUTE                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0006))             /* 0x7AE4 */
#define DP2_NSYNC_NOT_ETSI_C                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0006))             /* 0x7AE4 */
#define SPH_MUTE_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0006))             /* 0x7AE4 */
#define DP2_OFFSET_COUNT                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0007))             /* 0x7AE6 */
#define SPH_DEL_O                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0007))             /* 0x7AE6 */
#define DP2_NSYNC_VALUE                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0008))             /* 0x7AE8 */

#define DP2_SP_AUDIO_INTERFACE_CTRL_BASE    (DP2_SP_CODEC_CTRL_BASE + 0x0009)                                               /* 0x7AEA */

#define DP_AUDIO_ADDR                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0000))   /* 0x7AEA */
#define SPH_DL_VOL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0000))   /* 0x7AEA */
#define SPH_8K_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0001))   /* 0x7AEC */
#define AUDIO_PAR                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0001))   /* 0x7AEC */
#define SPH_UL_BKF_FLT_TAP                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0002))   /* 0x7AEE */
#define SPH_DL_BKF_FLT_TAP                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0004))   /* 0x7AF2 */
#define SPH_UL_VOL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0005))   /* 0x7AF4 */
#define SPH_ST_VOL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0006))   /* 0x7AF6 */
#define AUDIO_ASP_WAV_OUT_GAIN              (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0007))   /* 0x7AF8 */
#define SPH_PM_ADDR_BKF_FLT_COEF_UL_NB      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0008))   /* 0x7AFA */
#define SPH_PM_ADDR_BKF_FLT_COEF_DL_NB      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0009))   /* 0x7AFC */
#define SPH_PM_ADDR_BKF_FLT_COEF_UL_WB      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000A))   /* 0x7AFE */
#define SPH_PM_ADDR_BKF_FLT_COEF_DL_WB      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000B))   /* 0x7B00 */
#define SPH_PM_ADDR_ST_FLT_COEF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000C))   /* 0x7B02 */
#define SPH_PM_ADDR_SRC_FLT_COEF            (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000D))   /* 0x7B04 */
#define SPH_DM_ADDR_EMP                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000E))   /* 0x7B06 */
#define DP_BT_EARPHONE_MODE                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000F))   /* 0x7B08 */
#define SPH_BT_MODE                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000F))   /* 0x7B08 */
#define DP_ADAPTIVE_GAIN_CONTROL            (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0010))   /* 0x7B0A */
#define SPH_ENH_DL_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0010))   /* 0x7B0A */

#define DP2_SP_KT_CTRL_BASE                 (DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0013)                                     /* 0x7B10 */

#define DP_KEYTONE_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0000))                /* 0x7B10 */
#define KEYTONE1_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0000))                /* 0x7B10 */
#define KEYTONE2_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0001))                /* 0x7B12 */
#define DP_ASP_FORCE_KT_8K                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0002))                /* 0x7B14 */
#define KEYTONE1_FREQ1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0003))                /* 0x7B16 */
#define KEYTONE1_FREQ2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0004))                /* 0x7B18 */
#define KEYTONE1_AMP                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0005))                /* 0x7B1A */
#define KEYTONE2_FREQ1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0006))                /* 0x7B1C */
#define KEYTONE2_FREQ2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0007))                /* 0x7B1E */
#define KEYTONE2_AMP                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0008))                /* 0x7B20 */
#define DP_KEYTONE_ATT_GAIN                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0009))                /* 0x7B22 */
#define KEYTONE_ATT_GAIN_ADDR               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0009))                /* 0x7B22 */

#define DP2_SP_8KPCM_CTRL_BASE              (DP2_SP_KT_CTRL_BASE + 0x000A)                                                  /* 0x7B24 */

#define DP_ASP_WAV_REC_CTRL                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0000))             /* 0x7B24 */
#define ASP_WAV_REC_CTRL                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0000))             /* 0x7B24 */
#define DP_8KPCM_MIC_REC_IDX                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0001))             /* 0x7B26 */
#define ASP_WAV_REC_IDX                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0001))             /* 0x7B26 */
#define DP_8KPCM_MIC_REC_LEN                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0002))             /* 0x7B28 */
#define ASP_WAV_REC_LEN                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0002))             /* 0x7B28 */
#define DP_8KPCM_SPK_REC_IDX                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0003))             /* 0x7B2A */
#define ASP_DL_WAV_REC_IDX                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0003))             /* 0x7B2A */
#define DP_8KPCM_SPK_REC_LEN                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0004))             /* 0x7B2C */
#define ASP_DL_WAV_REC_LEN                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0004))             /* 0x7B2C */
#define SPH_PCM_REC_CTRL                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0005))             /* 0x7B2E */
#define SPH_DM_ADDR_EPL_UL_PRE_BUF          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0006))             /* 0x7B30 */
#define SPH_DM_ADDR_EPL_UL_POS_BUF          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0007))             /* 0x7B32 */
#define SPH_DM_ADDR_EPL_DL_PRE_BUF          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0008))             /* 0x7B34 */
#define SPH_DM_ADDR_EPL_DL_POS_BUF          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0009))             /* 0x7B36 */
#define SPH_DM_ADDR_SE2_PTR                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000A))             /* 0x7B38 */
#define DP_D2C_SPEECH_UL_INT                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000C))             /* 0x7B3C */
#define DP_D2C_SPEECH_DL_INT                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000D))             /* 0x7B3E */
#define DP_SPH_3G_SYNC_FLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000E))             /* 0x7B40 */
#define SPH_DM_ADDR_BGS_UL_BUF              (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000F))             /* 0x7B42 */
#define SPH_DM_ADDR_BGS_DL_BUF              (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0010))             /* 0x7B44 */
#define SPH_BGS_LEN_UL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0011))             /* 0x7B46 */
#define SPH_BGS_LEN_DL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0012))             /* 0x7B48 */
#define SPH_BGS_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0013))             /* 0x7B4A */
#define SPH_BGS_MIX                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0014))             /* 0x7B4C */

#define DP2_SP_VM_CTRL_BASE                 (DP2_SP_8KPCM_CTRL_BASE + 0x0015)                                               /* 0x7B4E */

#define DP_AWB_RX_TCH_S0_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0000))                /* 0x7B4E */
#define SPH_2G_SD_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0000))                /* 0x7B4E */
#define DP_SD1_VM_1                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0001))                /* 0x7B50 */
#define SPH_2G_SD_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0001))                /* 0x7B50 */
#define DP2_AWB_SD_TCH_MOD                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x001F))                /* 0x7B8C */
#define DP_AWB_TX_TCH_S0_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0020))                /* 0x7B8E */
#define SPH_2G_SE_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0020))                /* 0x7B8E */
#define DP_SD2_VM_1                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0021))                /* 0x7B90 */
#define SPH_2G_SE_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0021))                /* 0x7B90 */
#define DP_ENCODER_USED_MODE                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0042))                /* 0x7BD2 */
#define DP_DECODER_USED_MODE                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0043))                /* 0x7BD4 */
#define DP_VM_DBG_INFO                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0044))                /* 0x7BD6 */
#define DP_3G_DEBUG_INFO                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0044))                /* 0x7BD6 */
#define SPH_CTM_AMR_REAL_RX_TYPE            (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x007C))                /* 0x7C46 */

#define DP2_SP_CTM_BASE                     (DP2_SP_VM_CTRL_BASE + 0x0081)                                                  /* 0x7C50 */

#define SPH_DM_ADDR_PNW_UL1_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0000))                    /* 0x7C50 */
#define SPH_DM_ADDR_PNW_UL2_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0001))                    /* 0x7C52 */
#define SPH_DM_ADDR_PNW_DL1_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0002))                    /* 0x7C54 */
#define SPH_DM_ADDR_PNW_DL2_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0003))                    /* 0x7C56 */
#define SPH_PNW_CTRL_UL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0004))                    /* 0x7C58 */
#define SPH_PNW_CTRL_DL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0005))                    /* 0x7C5A */
#define SPH_CTM_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0006))                    /* 0x7C5C */
#define SPH_CTM_BFI_FACCH_REPORT            (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0007))                    /* 0x7C5E */
#define SPH_PNW_LEN_UL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0008))                    /* 0x7C60 */
#define SPH_PNW_LEN_DL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0009))                    /* 0x7C62 */
#define SPH_CTM_AMR_CODEBOOK_GAIN_LIMIT     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x000A))                    /* 0x7C64 */
#define SPH_CTM_AMR_CODEBOOK_GAIN_UPDATE    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x000B))                    /* 0x7C66 */
#define SPH_CTM_COSIM_CTRL                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x000C))                    /* 0x7C68 */

#define DP2_SP_AEC_CTRL_BASE                (DP2_SP_CTM_BASE + 0x000D)                                                      /* 0x7C6A */

#define DP_EC_CTRL_ADDR                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0000))               /* 0x7C6A */
#define DP2_EC_SUPP                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0000))               /* 0x7C6A */
#define SPH_ENH_UL_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0000))               /* 0x7C6A */
#define DP_AEC_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0001))               /* 0x7C6C */
#define DP_TDNC_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0001))               /* 0x7C6C */
#define DP_EES_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0002))               /* 0x7C6E */
#define DP_DMNR_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0003))               /* 0x7C70 */
#define DP_AEC_CONTROL_WORD                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0004))               /* 0x7C72 */
#define DP_EC_PAR_ADDR                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0007))               /* 0x7C74 */
#define DP2_ES_TIME_CONST                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0007))               /* 0x7C74 */
#define DP2_ES_VOL_CONST                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0008))               /* 0x7C76 */

#define DP2_SP_VR_CTRL_BASE                 (DP2_SP_AEC_CTRL_BASE + 0x000F)                                                 /* 0x7C88 */

#define DP_VR_CTRL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VR_CTRL_BASE + 0x0000))                /* 0x7C88 */
#define DP_VR_IO_BASE                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VR_CTRL_BASE + 0x0001))                /* 0x7C8A */
#define DP2_DATA_AP_DATA_UL                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VR_CTRL_BASE + 0x0004))                /* 0x7C90 */
#define DP2_DATA_AP_DATA_DL                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VR_CTRL_BASE + 0x0005))                /* 0x7C92 */

#define DP2_SP_AUDIO_CTRL_BASE              (DP2_SP_VR_CTRL_BASE + 0x000E)                                                  /* 0x7CA4 */

#define DP_TEST_SIM_SBSD_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0000))             /* 0x7CA4 */
#define DP2_TEST_SIM_IND                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0000))             /* 0x7CA4 */
#define AWB_LB_CHECKSUM_ADDR                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0001))             /* 0x7CA6 */
#define AFE_BT_LB_CHECKSUM_ADDR             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0001))             /* 0x7CA6 */
#define SPE_RAM_LB_CHECK_ADDR               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0001))             /* 0x7CA6 */
#define DP_AUDIO_CTRL2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0002))             /* 0x7CA8 */
#define DP_ENHANCED_AUDIO_CTRL              (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0003))             /* 0x7CAA */
#define SPH_SCH_IMPROVE_CTRL                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0005))             /* 0x7CAE */
#define SPH_BGS_UL_GAIN                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0006))             /* 0x7CB0 */
#define SPH_BGS_DL_GAIN                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0007))             /* 0x7CB2 */
#define SPH_3G_SE_RATE_UPDATE               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0008))             /* 0x7CB4 */
#define SPH_3G_SD_RATE_UPDATE               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0009))             /* 0x7CB6 */
#define DP_AWB_SE_CTRL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000A))             /* 0x7CB8 */
#define DP_AWB_SE_STATUS                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000A))             /* 0x7CB8 */
#define DP_AWB_SD_CTRL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000B))             /* 0x7CBA */
#define DP_AWB_SD_STATUS                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000B))             /* 0x7CBA */
#define DP_G723_SE_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000C))             /* 0x7CBC */
#define DP_G723_SD_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000D))             /* 0x7CBE */
#define DP_NR_CTRL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000E))             /* 0x7CC0 */

#define DP2_SP_AUDIO_ENHANCE_BASE           (DP2_SP_AUDIO_CTRL_BASE + 0x000F)                                               /* 0x7CC2 */

#define DP_DSP_DEAD_INT                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0000))          /* 0x7CC2 */
#define DP_AMR_MODE_ERROR_ASSERT_TYPE       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0001))          /* 0x7CC4 */
#define DP_AMR_MODE_ERROR_ASSERT_FLAG       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0002))          /* 0x7CC6 */
#define DP_AUDIO_FLEXI_CTRL                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0003))          /* 0x7CC8 */
#define DP_VOICE_CHG_SCH                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0004))          /* 0x7CCA */
#define DP_VOICE_CHG_TYPE                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0005))          /* 0x7CCC */
#define DP_BT_EARPHONE_UL_CONTROL           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0006))          /* 0x7CCE */
#define SPH_BT_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0006))          /* 0x7CCE */
#define SPH_DM_ADDR_SE_PTR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0007))          /* 0x7CD0 */
#define SPH_DM_ADDR_SD_PTR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0008))          /* 0x7CD2 */
#define DP_UP_DOWN_SAMPL_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0009))          /* 0x7CD4 */
#define DP_DL_NR_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000A))          /* 0x7CD6 */
#define DP_AUDIO_DAC_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000B))          /* 0x7CD8 */
#define DP_VBI_SYNC_BT_EARPHONE_CTRL        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000C))          /* 0x7CDA */
#define DP_SBSD_THRESHOLD                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000D))          /* 0x7CDC */
#define DP2_8K_SP_CTRL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000F))          /* 0x7CE0 */
#define SPH_SFE_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000F))          /* 0x7CE0 */
#define DP2_AUDIO_VIA_BT_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0010))          /* 0x7CE2 */
#define DP2_AUDIO_VIA_BT_INT                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0011))          /* 0x7CE4 */
#define DP2_AGC_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0012))          /* 0x7CE6 */
#define DP2_AGC_GAIN                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0013))          /* 0x7CE8 */
#define DP2_DATA_AP_CTRL                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0014))          /* 0x7CEA */
#define DP2_20MS_SP_CTRL                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0015))          /* 0x7CEC */
#define DP2_COMPEN_BLOCK_FILTER             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0015))          /* 0x7CEC */
#define DP_605_TASK_ID                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0016))          /* 0x7CEE */
#define DP_605_NO_8K_TASK_ID                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0017))          /* 0x7CF0 */

#define DP2_RESERVE_BASE                    (DP2_SP_AUDIO_ENHANCE_BASE + 0x0018)                                            /* 0x7CF2 */

#define SPH_3G_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_RESERVE_BASE + 0x0000))                   /* 0x7CF2 */
#define DP2_DDL_MCU_DSP_HAND_SHAKE          (*(volatile uint16_t *)DPRAM_BASE(DP2_RESERVE_BASE + 0x0001))                   /* 0x7CF4 */

#define DP2_AWB_8K_BASE                     (DP2_RESERVE_BASE + 0x0002)                                                     /* 0x7CF6 */

#define DP2_RINI_INT                        (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_8K_BASE + 0x0006))                    /* 0x7D02 */
#define DP2_DL_RIN_SIG_ENERGY               (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_8K_BASE + 0x0007))                    /* 0x7D04 */
#define SPH_DYNA_FWLA_MODE_CTRL             (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_8K_BASE + 0x0008))                    /* 0x7D06 */

#define DP2_EPL_BND_BASE                    (DP2_AWB_8K_BASE + 0x0009)                                                      /* 0x7D08 */

#define SPH_EPL_BND                         (*(volatile uint16_t *)DPRAM_BASE(DP2_EPL_BND_BASE + 0x0000))                   /* 0x7D08 */

#define DP2_AWB_LINK_EXTEND_BASE            (DP2_EPL_BND_BASE + 0x0001)                                                     /* 0x7D0A */

#define DP_SD1_AWB_VM_0                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0000))           /* 0x7D0A */
#define DP_3G_RX_VM_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0000))           /* 0x7D0A */
#define SPH_3G_SD_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0000))           /* 0x7D0A */
#define SPH_AP_SD_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0000))           /* 0x7D0A */
#define DP_ORG_SD1_VM_1                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0001))           /* 0x7D0C */
#define SPH_3G_SD_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0001))           /* 0x7D0C */
#define SPH_AP_SD_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0001))           /* 0x7D0C */
#define DP_SD2_AWB_VM_0                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0020))           /* 0x7D4A */
#define DP_3G_TX_VM_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0020))           /* 0x7D4A */
#define SPH_3G_SE_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0020))           /* 0x7D4A */
#define SPH_AP_SE_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0020))           /* 0x7D4A */
#define DP_ORG_SD2_VM_1                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0021))           /* 0x7D4C */
#define SPH_3G_SE_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0021))           /* 0x7D4C */
#define SPH_AP_SE_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0021))           /* 0x7D4C */
#define DP_SD2_AWB_VM_18                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0032))           /* 0x7D6E */
#define DP_WB_DEBUG_INFO                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0040))           /* 0x7D8A */

#define DP_SPEECH_OTHER_BASE                (DP2_AWB_LINK_EXTEND_BASE + 0x004C)                                             /* 0x7DA2 */

#define DP_UL_COMFORT_NOISE_THRESHOLD       (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0000))               /* 0x7DA2 */
#define DP_UL_COMFORT_NOISE_SHIFT           (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0001))               /* 0x7DA4 */
#define DP_DTX_DSPK_FUN_CTRL_ADDR           (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0002))               /* 0x7DA6 */
#define DP_HR_BER_THD_ADDR                  (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0003))               /* 0x7DA8 */
#define DP_FR_BER_THD_ADDR                  (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0004))               /* 0x7DAA */
#define DP_EFR_BER_THD_ADDR                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0005))               /* 0x7DAC */
#define DP2_TIME_STAMP_2G_H                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0006))               /* 0x7DAE */
#define DP2_TIME_STAMP_2G_L                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0007))               /* 0x7DB0 */
#define DP2_TIME_STAMP_3G_H                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0008))               /* 0x7DB2 */
#define DP2_TIME_STAMP_3G_L                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0009))               /* 0x7DB4 */
#define DP2_SPEECH_DEBUG_MODE               (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000A))               /* 0x7DB6 */
#define SPH_DBG_MOD                         (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000A))               /* 0x7DB6 */
#define DP2_ABF_CTRL_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000B))               /* 0x7DB8 */
#define DP2_ABF_CTRL_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000C))               /* 0x7DBA */
#define SPH_DUMIC_CTRL                      (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000D))               /* 0x7DBC */

#define DP_SPEECH_RESERVED_BASE             (DP_SPEECH_OTHER_BASE + 0x000E)                                                 /* 0x7DBE */

#define DP_SPH_COSIM_RESULT_REPORT          (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0000))            /* 0x7DBE */
#define DP_SPH_COSIM_FAIL_TYPE              (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0001))            /* 0x7DC0 */
#define DP_SPH_SPECIAL_LOOPBACK_CTRL        (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0002))            /* 0x7DC2 */
#define DP_TASK5_COSIM_HANDSHAKE            (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0003))            /* 0x7DC4 */
#define DP_AGC_SW_GAIN1                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0004))            /* 0x7DC6 */
#define DP_AGC_SW_GAIN2                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0005))            /* 0x7DC8 */
#define SPH_DACA_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0006))            /* 0x7DCA */
#define SPH_DM_ADDR_DACA_UL_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0007))            /* 0x7DCC */
#define SPH_DM_ADDR_DACA_DL_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0008))            /* 0x7DCE */
#define SPH_DACA_LEN_UL                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0009))            /* 0x7DD0 */
#define SPH_DACA_LEN_DL                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000A))            /* 0x7DD2 */
#define SPH_SW_TRANSC_SD_CNTR               (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000B))            /* 0x7DD4 */
#define SPH_SW_TRANSC_TAF_CNTR              (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000C))            /* 0x7DD6 */
#define SPH_APP_MODE                        (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000D))            /* 0x7DD8 */
#define SPH_VOLTE_JBM_CTRL                  (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000E))            /* 0x7DDA */
#define SPH_PCM_FRM_PEAK_UL                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000F))            /* 0x7DDC */
#define SPH_PCM_FRM_PEAK_DL                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0010))            /* 0x7DDE */
#define SPH_WARN_MSG_UL                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0011))            /* 0x7DE0 */
#define SPH_WARN_MSG_DL                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0012))            /* 0x7DE2 */
#define SPH_8K_RESYNC_CTRL                  (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0013))            /* 0x7DE4 */
#define SPH_8K_RESYNC_OFFSET_UL             (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0014))            /* 0x7DE6 */
#define SPH_8K_RESYNC_OFFSET_DL             (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0015))            /* 0x7DE8 */
#define SPH_8K_DIS_VBI_CTRL                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0016))            /* 0x7DEA */

#define DP2_AUDIO_CTRL_FIELD_BASE           (DP_SPEECH_RESERVED_BASE + 0x0019)                                              /* 0x7DF0 */

#define DP_AUDIO_ASP_TYPE_ADDR              (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0000))          /* 0x7DF0 */
#define DP_AUDIO_ASP_FS_ADDR                (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0001))          /* 0x7DF2 */
#define DP_AUDIO_ASP_DEL_W_ADDR             (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0002))          /* 0x7DF4 */
#define DP_AUDIO_DEC_FRAME_LENGTH           (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0003))          /* 0x7DF6 */
#define DP_AUDIO_ASP_DEL_MARGIN_W_ADDR      (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0004))          /* 0x7DF8 */
#define DP_VOL_OUT                          (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0005))          /* 0x7DFA */

#define A2V_BASE                            (DP2_AUDIO_CTRL_FIELD_BASE + 0x0006)                                            /* 0x7DFC */

#define A2V_INT_ENABLE                      (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0000))                           /* 0x7DFC */
#define A2V_INT_CNT                         (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0001))                           /* 0x7DFE */
#define A2V_INT_STAMP                       (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0002))                           /* 0x7E00 */
#define A2V_AUDIO_FRMAE_COUNT               (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0003))                           /* 0x7E02 */
#define A2V_VIDEO_FRAME_COUNT               (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0004))                           /* 0x7E04 */
#define A2V_INT_DSP_COUNT                   (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0005))                           /* 0x7E06 */
#define A2V_INTERRUPT_PADDING_FLAG          (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0006))                           /* 0x7E08 */
#define A2V_SPEECH_COUNT                    (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0007))                           /* 0x7E0A */

#define DP2_WAV_CTRL_FIELD_BASE             (A2V_BASE + 0x0008)                                                             /* 0x7E0C */

#define DP_ASP_WAV_BASE_CTRL                (*(volatile uint16_t *)DPRAM_BASE(DP2_WAV_CTRL_FIELD_BASE + 0x0000))            /* 0x7E0C */
#define DP_ASP_WAV_W_IO_ADDR                (*(volatile uint16_t *)DPRAM_BASE(DP2_WAV_CTRL_FIELD_BASE + 0x0001))            /* 0x7E0E */
#define DP_ASP_WAV_R_IO_ADDR                (*(volatile uint16_t *)DPRAM_BASE(DP2_WAV_CTRL_FIELD_BASE + 0x0002))            /* 0x7E10 */
#define DP2_WAV_STEREO_FLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP2_WAV_CTRL_FIELD_BASE + 0x0003))            /* 0x7E12 */

#define DP2_WT_CTRL_FIELD_BASE              (DP2_WAV_CTRL_FIELD_BASE + 0x0004)                                              /* 0x7E14 */

#define DP_WT_CONTROL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_WT_CTRL_FIELD_BASE + 0x0000))             /* 0x7E14 */

#define DP2_MP3_CTRL_FIELD_BASE             (DP2_WT_CTRL_FIELD_BASE + 0x0001)                                               /* 0x7E16 */

#define MP3_CONTROL_BASE_ADD                (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0000))            /* 0x7E16 */
#define MP3_CONTROL_1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0001))            /* 0x7E18 */
#define MP3_CONTROL_2                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0002))            /* 0x7E1A */
#define MP3_CONTROL_3                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0003))            /* 0x7E1C */
#define MP3_CONTROL_4                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0004))            /* 0x7E1E */
#define MP3_CONTROL_5                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0005))            /* 0x7E20 */
#define MP3_CONTROL_6                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0006))            /* 0x7E22 */
#define MP3_CONTROL_7                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0007))            /* 0x7E24 */
#define MP3_CONTROL_8                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0008))            /* 0x7E26 */
#define MP3_CONTROL_9                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0009))            /* 0x7E28 */
#define MP3_CONTROL_10                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000A))            /* 0x7E2A */
#define MP3_CONTROL_11                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000B))            /* 0x7E2C */
#define MP3_CONTROL_12                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000C))            /* 0x7E2E */
#define MP3_CONTROL_13                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000D))            /* 0x7E30 */
#define MP3_CONTROL_14                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000E))            /* 0x7E32 */
#define MP3_CONTROL_15                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000F))            /* 0x7E34 */
#define MP3_CONTROL_16                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0010))            /* 0x7E36 */
#define MP3_CONTROL_17                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0011))            /* 0x7E38 */
#define MP3_CONTROL_18                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0012))            /* 0x7E3A */
#define MP3_CONTROL_19                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0013))            /* 0x7E3C */
#define MP3_CONTROL_20                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0014))            /* 0x7E3E */
#define MP3_CONTROL_21                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0015))            /* 0x7E40 */
#define MP3_CONTROL_22                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0016))            /* 0x7E42 */
#define MP3_CONTROL_23                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0017))            /* 0x7E44 */
#define MP3_CONTROL_24                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0018))            /* 0x7E46 */
#define MP3_CONTROL_25                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0019))            /* 0x7E48 */
#define MP3_CONTROL_26                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x001A))            /* 0x7E4A */
#define MP3_CONTROL_27                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x001B))            /* 0x7E4C */
#define MP3_CONTROL_28                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x001C))            /* 0x7E4E */

#define DP2_AUDIO_PP_CTRL_BASE              (DP2_MP3_CTRL_FIELD_BASE + 0x001D)                                              /* 0x7E50 */

#define DP2_AUDIO_PP_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0000))             /* 0x7E50 */
#define DP_AUDIO_GAIN_STEP                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0001))             /* 0x7E52 */
#define AUDIO_PP_TS_SPEED                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0002))             /* 0x7E54 */
#define AUDIO_PP_RESERVEA1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0003))             /* 0x7E56 */
#define AUDIO_DEBUG_SHERIF1                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0003))             /* 0x7E56 */
#define AUDIO_PP_TS_APM_TO_DSP_LENGTH       (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0004))             /* 0x7E58 */
#define AUD_VSG_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0005))             /* 0x7E5A */
#define VS_MOD_FREQ                         (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0006))             /* 0x7E5C */
#define VS_CENTER_FREQ                      (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0007))             /* 0x7E5E */
#define VS_DIGI_GAIN                        (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0008))             /* 0x7E60 */
#define AUDIO_PP_RESERVEA6                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0009))             /* 0x7E62 */
#define AUDIO_PP_RESERVEA7                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000A))             /* 0x7E64 */
#define DP_AUDIO_DEC_CNTR_THRESHOLD         (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000B))             /* 0x7E66 */
#define DP_AUDIO_CUR_GAIN                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000C))             /* 0x7E68 */
#define AUDIO_CHECK_ASP_TYPE                (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000D))             /* 0x7E6A */
#define PCM_ROUNT_DATA_ADDRESS              (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000E))             /* 0x7E6C */
#define PCM_ROUNT_DATA_LENGTH               (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000F))             /* 0x7E6E */
#define PCM_ROUNT_DATA_PAGENUM              (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0010))             /* 0x7E70 */
#define AUDIO_PP_RESERVEC1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0011))             /* 0x7E72 */
#define AUDIO_32K_RECORD_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0012))             /* 0x7E74 */
#define DYNAMIC_DOWNLOAD_MCU_STATUS         (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0013))             /* 0x7E76 */
#define DYNAMIC_DOWNLOAD_STATUS             (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0014))             /* 0x7E78 */

#define DP2_EXTRA_APPLICATION_FILED_BASE    (DP2_AUDIO_PP_CTRL_BASE + 0x0015)                                               /* 0x7E7A */

#define DP_AUDIO_ASP_COMMON_FLAG_1          (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0000))   /* 0x7E7A */
#define AUDIO_RAMPDOWN_ENABLE               (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0001))   /* 0x7E7C */
#define AUDIO_SD_ISR_CYCLE                  (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0002))   /* 0x7E7E */
#define DP_AUDIO_ASP_COMMON_FLAG_2          (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0003))   /* 0x7E80 */
#define DP_AUDIO_ASP_D2M_COUNT              (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0004))   /* 0x7E82 */
#define DP_TASK4_COSIM_HANDSHAKE            (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0005))   /* 0x7E84 */

#define DP2_DYNAMIC_LOAD_FIELD_BASE         (DP2_EXTRA_APPLICATION_FILED_BASE + 0x0006)                                     /* 0x7E86 */

#define DDL_TASK_FLAG                       (*(volatile uint16_t *)DPRAM_BASE(DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0000))        /* 0x7E86 */
#define DP2_DYNAMIC_LOAD_FIELD              (*(volatile uint16_t *)DPRAM_BASE(DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0000))        /* 0x7E86 */
#define DDL_CHECK_POSITION                  (*(volatile uint16_t *)DPRAM_BASE(DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0001))        /* 0x7E88 */
#define DDL_TASK_ID                         (*(volatile uint16_t *)DPRAM_BASE(DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0002))        /* 0x7E8A */

#define DP2_AUDIO_RESERVED_BASE             (DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0003)                                          /* 0x7E8C */

#define DP2_AUDIO_RESERVED_BASE1            (DP2_AUDIO_RESERVED_BASE + 0x0000)                                              /* 0x7E8C */
#define DP2_AUDIO_RESERVED_BASE2            (DP2_AUDIO_RESERVED_BASE + 0x0001)                                              /* 0x7E8E */

#define DP2_UNDEFINEDD_BASE                 (DP2_AUDIO_RESERVED_BASE + 0x0002)                                              /* 0x7E90 */

#endif /* _DPRAM_H_ */
