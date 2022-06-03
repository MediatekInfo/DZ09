#ifndef _DPRAM_H_
#define _DPRAM_H_

#define DPRAM_BASE(v)                       (DPRAM_CPU_BASE + 2 * (v))

#define DP_DSP_TASK_STATUS_BASE             0x3A00                                                                          /* 0x3A00 */

#define DP_DSP_STATUS                       (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0000))            /* 0x3A00 */
#define DP_MCU_STATUS                       (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0001))            /* 0x3A01 */
#define DP_DSP_STATUS_MTCMOS                (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0002))            /* 0x3A02 */
#define DP_MCU_STATUS_MTCMOS                (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0003))            /* 0x3A03 */
#define DEBUG_ASSERT_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0004))            /* 0x3A04 */
#define DTIRQ_DEBUG_ASSERT_CHECK            (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0005))            /* 0x3A05 */
#define DP_RX_WIN_COUNT                     (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0006))            /* 0x3A06 */
#define DP2_RX_S0_CD_DONE                   (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0007))            /* 0x3A07 */
#define DP_SLOW_IDLE_DIVIDER                (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0008))            /* 0x3A08 */
#define DP_DSP_ROM_VERSION                  (*(volatile uint16_t *)DPRAM_BASE(DP_DSP_TASK_STATUS_BASE + 0x0009))            /* 0x3A09 */

#define DP_RX_WINDOW_BASE                   (DP_DSP_TASK_STATUS_BASE + 0x000A)                                              /* 0x3A0A */

#define DP_RX_WIN0_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0000))                  /* 0x3A0A */
#define DP_RX_WIN1_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0001))                  /* 0x3A0B */
#define DP_RX_WIN2_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0002))                  /* 0x3A0C */
#define DP_RX_WIN3_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0003))                  /* 0x3A0D */
#define DP_RX_WIN4_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0004))                  /* 0x3A0E */
#define DP_RX_WIN5_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0005))                  /* 0x3A0F */
#define DP_RX_WIN6_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0006))                  /* 0x3A10 */
#define DP_RX_WIN7_PROC                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0007))                  /* 0x3A11 */
#define DP_RX_WIN0_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0008))                  /* 0x3A12 */
#define DP_RX_WIN1_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x0009))                  /* 0x3A13 */
#define DP_RX_WIN2_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x000A))                  /* 0x3A14 */
#define DP_RX_WIN3_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x000B))                  /* 0x3A15 */
#define DP_RX_WIN4_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x000C))                  /* 0x3A16 */
#define DP_RX_WIN5_FREQ                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_WINDOW_BASE + 0x000D))                  /* 0x3A17 */

#define DP2_TX_WINDOW_BASE                  (DP_RX_WINDOW_BASE + 0x000E)                                                    /* 0x3A18 */

#define DP2_TX_WIN0_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0000))                 /* 0x3A18 */
#define DP2_TX_WIN1_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0001))                 /* 0x3A19 */
#define DP2_TX_WIN2_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0002))                 /* 0x3A1A */
#define DP2_TX_WIN3_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0003))                 /* 0x3A1B */
#define DP2_TX_WIN4_PROC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_WINDOW_BASE + 0x0004))                 /* 0x3A1C */

#define DP2_ENCRYPTION_BASE                 (DP2_TX_WINDOW_BASE + 0x0005)                                                   /* 0x3A1D */

#define DP2_CRYPT_PAR_0                     (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0000))                /* 0x3A1D */
#define DP2_ENCRYP_KEY_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0001))                /* 0x3A1E */
#define DP2_ENCRYP_KEY_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0002))                /* 0x3A1F */
#define DP2_ENCRYP_KEY_3                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0003))                /* 0x3A20 */
#define DP2_ENCRYP_KEY_4                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPTION_BASE + 0x0004))                /* 0x3A21 */

#define DP_EQ_CHANNEL_CODEC_BASE            (DP2_ENCRYPTION_BASE + 0x0005)                                                  /* 0x3A22 */

#define DP_CHEST_RENULL_SN_ALPHA            (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0000))           /* 0x3A22 */
#define DP_RX_BUFFER_LEN                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0001))           /* 0x3A23 */
#define DP_NB_TRX                           (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0002))           /* 0x3A24 */
#define DP_FCCH_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0003))           /* 0x3A25 */
#define DP_FCB_CONSEC                       (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0004))           /* 0x3A26 */
#define DP_FCB1_LANDA_FXP                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0005))           /* 0x3A27 */
#define DP_FCB2_LANDA_FXP                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0006))           /* 0x3A28 */
#define DP_FCB1_COST_THRESHOLD_FXP          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0007))           /* 0x3A29 */
#define DP_FCB2_COST_THRESHOLD_FXP          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0008))           /* 0x3A2A */
#define DP_FCB_FOE_TH                       (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0009))           /* 0x3A2B */
#define DP_SHORT_FB_BURST_LEN               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000A))           /* 0x3A2C */
#define DP_SHORT_FB_RESCALING_FACTOR        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000B))           /* 0x3A2D */
#define DP_SHORT_FB_RESOLUTION              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000C))           /* 0x3A2E */
#define DP_SHORT_FB_DC_AVE_LEN              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000D))           /* 0x3A2F */
#define DP_SHORT_FB_BER_THR                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000E))           /* 0x3A30 */
#define DP_SHORT_FB_DIST_THR                (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x000F))           /* 0x3A31 */
#define DP_SHORT_SB_BURST_LEN               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0010))           /* 0x3A32 */
#define DP_SHORT_SB_RESCALING_FACTOR        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0011))           /* 0x3A33 */
#define DP_SHORT_SB_RESOLUTION              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0012))           /* 0x3A34 */
#define DP_FB_2ND_INIT_FLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0013))           /* 0x3A35 */
#define DP_CC_FLAG                          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0014))           /* 0x3A36 */
#define DP_PM_LENGTH_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0015))           /* 0x3A37 */
#define DP_PHASE_IMB_FACTOR                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0016))           /* 0x3A38 */
#define DP_STEPDC_THRES                     (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0017))           /* 0x3A39 */
#define DP_CHEST_LEN_ALPHA                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0018))           /* 0x3A3A */
#define DP_STATIC_STATE                     (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x0019))           /* 0x3A3B */
#define DP_CW_POSITION                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x001A))           /* 0x3A3C */
#define DP_QBIT_CW_SWITCH                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x001B))           /* 0x3A3D */
#define DP_NB_RANGE_WIN                     (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CHANNEL_CODEC_BASE + 0x001C))           /* 0x3A3E */

#define DP_EQ_SAIC_BASE                     (DP_EQ_CHANNEL_CODEC_BASE + 0x001D)                                             /* 0x3A3F */

#define DP_RX_SAIC_SWITCH                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0000))                    /* 0x3A3F */
#define DP_RX_SAIC_THRES                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0001))                    /* 0x3A40 */
#define DP_EPSK_SAIC_PWR_TH                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0002))                    /* 0x3A41 */
#define DP_EPSK_SAIC_SN_TH                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0003))                    /* 0x3A42 */
#define DP_ANT_PWR_OFFSET                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0004))                    /* 0x3A43 */
#define DP_DSP_PWR_UNDERFLOW                (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0005))                    /* 0x3A44 */
#define DP_BEP_K1_GMSK                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0006))                    /* 0x3A45 */
#define DP_BEP_K2_GMSK                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0007))                    /* 0x3A46 */
#define DP_BEP_K1_EPSK                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0008))                    /* 0x3A47 */
#define DP_BEP_K2_EPSK                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x0009))                    /* 0x3A48 */
#define DP_BEP_K1_GMSK_SAIC_ON              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x000A))                    /* 0x3A49 */
#define DP_BEP_K2_GMSK_SAIC_ON              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x000B))                    /* 0x3A4A */
#define DP_BEP_K1_EPSK_SAIC_ON              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x000C))                    /* 0x3A4B */
#define DP_BEP_K2_EPSK_SAIC_ON              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_SAIC_BASE + 0x000D))                    /* 0x3A4C */

#define DP_EQ_CONTROL_BASE                  (DP_EQ_SAIC_BASE + 0x000E)                                                      /* 0x3A4D */

#define DP_MODDET_THRES                     (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0000))                 /* 0x3A4D */
#define DP_CHEST_LEN35_SN_TH                (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0001))                 /* 0x3A4E */
#define DP_CHEST_LEN_TSNR                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0002))                 /* 0x3A4F */
#define DP_CHEST_LEN_T23                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0003))                 /* 0x3A50 */
#define DP_CHEST_LEN_T35                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0004))                 /* 0x3A51 */
#define DP_CHEST_LEN_T57                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0005))                 /* 0x3A52 */
#define DP_CHEST_NT_GMSK                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0006))                 /* 0x3A53 */
#define DP_CHEST_NT_EPSK                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0007))                 /* 0x3A54 */
#define DP_CHEST_LEN_ALPHA_1THR             (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0008))                 /* 0x3A55 */
#define DP_CHEST_LEN_ALPHA_0THR             (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0009))                 /* 0x3A56 */
#define DP_CHEST_NULL_SNTHR_H               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000A))                 /* 0x3A57 */
#define DP_CHEST_NULL_SNTHR_L               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000B))                 /* 0x3A58 */
#define DP_CHEST_RENULL_TH                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000C))                 /* 0x3A59 */
#define DP_CHEST_RENULL_ALPHA_CNT_TH        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000D))                 /* 0x3A5A */
#define DP_CHEST_SAIC_PARA_NB               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000E))                 /* 0x3A5B */
#define DP_CHEST_SAIC_PARA_SB               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x000F))                 /* 0x3A5C */
#define DP_CHEST_SAIC_SP_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0010))                 /* 0x3A5D */
#define DP_CHEST_SAIC_LEN_T35_SNH           (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0011))                 /* 0x3A5E */
#define DP_CHEST_SAIC_LEN_T35_SNL           (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0012))                 /* 0x3A5F */
#define DP_CHEST_SAIC_CIRTHRES              (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0013))                 /* 0x3A60 */
#define DP_AMR_LS_DC_SNTHR                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0014))                 /* 0x3A61 */
#define DP_EPSK_SAIC_PARA                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0015))                 /* 0x3A62 */
#define DP_SINR_GMSK_FACTOR                 (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0016))                 /* 0x3A63 */
#define DP_SINR_EPSK_FACTOR_SAIC_ON         (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0017))                 /* 0x3A64 */
#define DP_SINR_EPSK_FACTOR_SAIC_OFF        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0018))                 /* 0x3A65 */
#define DP_FOE_SINR_SHIFT                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0019))                 /* 0x3A66 */
#define DP_FOE_GMSK_FACTOR                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001A))                 /* 0x3A67 */
#define DP_FOE_EPSK_FACTOR                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001B))                 /* 0x3A68 */
#define DP_FOE_LEN                          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001C))                 /* 0x3A69 */
#define DP_FOE_INV_SUMK2                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001D))                 /* 0x3A6A */
#define DP_CS4_BEP_TH1                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001E))                 /* 0x3A6B */
#define DP_EQCFG_PFLEN                      (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x001F))                 /* 0x3A6C */
#define DP_EQCFG_LMS                        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0020))                 /* 0x3A6D */
#define DP_EQCFG_LMSTHRES                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0021))                 /* 0x3A6E */
#define DP_EQCFG_PLL                        (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0022))                 /* 0x3A6F */
#define DP_EQCFG_PLLTHRES                   (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0023))                 /* 0x3A70 */
#define DP_EQCFG_DARPPLL                    (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0024))                 /* 0x3A71 */
#define DP_EQCFG_DARPPLLTHRES               (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0025))                 /* 0x3A72 */
#define DP_EQCFG_SAIC_LMS_STEPSIZE          (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0026))                 /* 0x3A73 */
#define DP_SINR_FWBW_THRES                  (*(volatile uint16_t *)DPRAM_BASE(DP_EQ_CONTROL_BASE + 0x0027))                 /* 0x3A74 */

#define DP_VAMOS_CONTROL_BASE               (DP_EQ_CONTROL_BASE + 0x0028)                                                   /* 0x3A75 */

#define DP_VAMOS_ENABLE                     (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0000))              /* 0x3A75 */
#define DP_VAMOS_TSCSNR_SH                  (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0001))              /* 0x3A76 */
#define DP_VAMOS_TSCSNR_CONST               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0002))              /* 0x3A77 */
#define DP_VAMOS_BEP_K3                     (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0003))              /* 0x3A78 */
#define DP_VAMOS_BEP_K4                     (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0004))              /* 0x3A79 */
#define DP_VAMOS_SAIC_PARA                  (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0005))              /* 0x3A7A */
#define DP2_VAMOS_BFI_MEAN_SNTH             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0006))              /* 0x3A7B */
#define DP2_VAMOS_BFI_D_TH                  (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0007))              /* 0x3A7C */
#define DP_VAMOS_BFI_SN_THRES               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0008))              /* 0x3A7D */
#define DP_FOE_AQPSK_FACTOR                 (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x0009))              /* 0x3A7E */
#define DP_SOC3_ENABLE_DC_CANCELLATION      (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000A))              /* 0x3A7F */
#define DP_VAMOS_ZETA_TH                    (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000B))              /* 0x3A80 */
#define DP_VAMOS_LS_DC_SNTHR                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000C))              /* 0x3A81 */
#define DP_VAMOS_LS_DC_PTHR1                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000D))              /* 0x3A82 */
#define DP_VAMOS_LS_DC_PTHR2                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_CONTROL_BASE + 0x000E))              /* 0x3A83 */

#define DP_VAMOS_ZETA_BASE                  (DP_VAMOS_CONTROL_BASE + 0x0010)                                                /* 0x3A85 */

#define DP_VAMOS_ZETA_THR_10                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0000))                 /* 0x3A85 */
#define DP_VAMOS_ZETA_THR_11                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0001))                 /* 0x3A86 */
#define DP_VAMOS_ZETA_THR_12                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0002))                 /* 0x3A87 */
#define DP_VAMOS_ZETA_THR_13                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0003))                 /* 0x3A88 */
#define DP_VAMOS_ZETA_THR_20                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0004))                 /* 0x3A89 */
#define DP_VAMOS_ZETA_THR_21                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0005))                 /* 0x3A8A */
#define DP_VAMOS_ZETA_THR_22                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0006))                 /* 0x3A8B */
#define DP_VAMOS_ZETA_THR_23                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0007))                 /* 0x3A8C */
#define DP_VAMOS_ZETA_THR_30                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0008))                 /* 0x3A8D */
#define DP_VAMOS_ZETA_THR_31                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x0009))                 /* 0x3A8E */
#define DP_VAMOS_ZETA_THR_32                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000A))                 /* 0x3A8F */
#define DP_VAMOS_ZETA_THR_33                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000B))                 /* 0x3A90 */
#define DP_VAMOS_ZETA_THR_40                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000C))                 /* 0x3A91 */
#define DP_VAMOS_ZETA_THR_41                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000D))                 /* 0x3A92 */
#define DP_VAMOS_ZETA_THR_50                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000E))                 /* 0x3A93 */
#define DP_VAMOS_ZETA_THR_51                (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_ZETA_BASE + 0x000F))                 /* 0x3A94 */

#define DP_VAMOS_BEP_BASE                   (DP_VAMOS_ZETA_BASE + 0x0010)                                                   /* 0x3A95 */

#define DP_VAMOS_BEP_SCALING_0              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0000))                  /* 0x3A95 */
#define DP_VAMOS_BEP_OFFSET_0               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0001))                  /* 0x3A96 */
#define DP_VAMOS_BEP_SCALING_1              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0002))                  /* 0x3A97 */
#define DP_VAMOS_BEP_OFFSET_1               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0003))                  /* 0x3A98 */
#define DP_VAMOS_BEP_SCALING_2              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0004))                  /* 0x3A99 */
#define DP_VAMOS_BEP_OFFSET_2               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0005))                  /* 0x3A9A */
#define DP_VAMOS_BEP_SCALING_3              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0006))                  /* 0x3A9B */
#define DP_VAMOS_BEP_OFFSET_3               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0007))                  /* 0x3A9C */
#define DP_VAMOS_BEP_SCALING_4              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0008))                  /* 0x3A9D */
#define DP_VAMOS_BEP_OFFSET_4               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0009))                  /* 0x3A9E */
#define DP_VAMOS_BEP_SCALING_5              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000A))                  /* 0x3A9F */
#define DP_VAMOS_BEP_OFFSET_5               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000B))                  /* 0x3AA0 */
#define DP_VAMOS_BEP_SCALING_6              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000C))                  /* 0x3AA1 */
#define DP_VAMOS_BEP_OFFSET_6               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000D))                  /* 0x3AA2 */
#define DP_VAMOS_BEP_SCALING_7              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000E))                  /* 0x3AA3 */
#define DP_VAMOS_BEP_OFFSET_7               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x000F))                  /* 0x3AA4 */
#define DP_VAMOS_BEP_SCALING_8              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0010))                  /* 0x3AA5 */
#define DP_VAMOS_BEP_OFFSET_8               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0011))                  /* 0x3AA6 */
#define DP_VAMOS_BEP_SCALING_9              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0012))                  /* 0x3AA7 */
#define DP_VAMOS_BEP_OFFSET_9               (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0013))                  /* 0x3AA8 */
#define DP_VAMOS_BEP_SCALING_10             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0014))                  /* 0x3AA9 */
#define DP_VAMOS_BEP_OFFSET_10              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0015))                  /* 0x3AAA */
#define DP_VAMOS_BEP_SCALING_11             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0016))                  /* 0x3AAB */
#define DP_VAMOS_BEP_OFFSET_11              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0017))                  /* 0x3AAC */
#define DP_VAMOS_BEP_SCALING_12             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0018))                  /* 0x3AAD */
#define DP_VAMOS_BEP_OFFSET_12              (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_BEP_BASE + 0x0019))                  /* 0x3AAE */

#define DP_VAMOS_AMRQI_BASE                 (DP_VAMOS_BEP_BASE + 0x001A)                                                    /* 0x3AAF */

#define DP_VAMOS_AMRQI_SCALING_0            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0000))                /* 0x3AAF */
#define DP_VAMOS_AMRQI_OFFSET_0             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0001))                /* 0x3AB0 */
#define DP_VAMOS_AMRQI_SCALING_1            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0002))                /* 0x3AB1 */
#define DP_VAMOS_AMRQI_OFFSET_1             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0003))                /* 0x3AB2 */
#define DP_VAMOS_AMRQI_SCALING_2            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0004))                /* 0x3AB3 */
#define DP_VAMOS_AMRQI_OFFSET_2             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0005))                /* 0x3AB4 */
#define DP_VAMOS_AMRQI_SCALING_3            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0006))                /* 0x3AB5 */
#define DP_VAMOS_AMRQI_OFFSET_3             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0007))                /* 0x3AB6 */
#define DP_VAMOS_AMRQI_SCALING_4            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0008))                /* 0x3AB7 */
#define DP_VAMOS_AMRQI_OFFSET_4             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0009))                /* 0x3AB8 */
#define DP_VAMOS_AMRQI_SCALING_5            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000A))                /* 0x3AB9 */
#define DP_VAMOS_AMRQI_OFFSET_5             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000B))                /* 0x3ABA */
#define DP_VAMOS_AMRQI_SCALING_6            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000C))                /* 0x3ABB */
#define DP_VAMOS_AMRQI_OFFSET_6             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000D))                /* 0x3ABC */
#define DP_VAMOS_AMRQI_SCALING_7            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000E))                /* 0x3ABD */
#define DP_VAMOS_AMRQI_OFFSET_7             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x000F))                /* 0x3ABE */
#define DP_VAMOS_AMRQI_SCALING_8            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0010))                /* 0x3ABF */
#define DP_VAMOS_AMRQI_OFFSET_8             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0011))                /* 0x3AC0 */
#define DP_VAMOS_AMRQI_SCALING_9            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0012))                /* 0x3AC1 */
#define DP_VAMOS_AMRQI_OFFSET_9             (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0013))                /* 0x3AC2 */
#define DP_VAMOS_AMRQI_SCALING_10           (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0014))                /* 0x3AC3 */
#define DP_VAMOS_AMRQI_OFFSET_10            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0015))                /* 0x3AC4 */
#define DP_VAMOS_AMRQI_SCALING_11           (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0016))                /* 0x3AC5 */
#define DP_VAMOS_AMRQI_OFFSET_11            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0017))                /* 0x3AC6 */
#define DP_VAMOS_AMRQI_SCALING_12           (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0018))                /* 0x3AC7 */
#define DP_VAMOS_AMRQI_OFFSET_12            (*(volatile uint16_t *)DPRAM_BASE(DP_VAMOS_AMRQI_BASE + 0x0019))                /* 0x3AC8 */

#define DP_IRDMA_BASE                       (DP_VAMOS_AMRQI_BASE + 0x001A)                                                  /* 0x3AC9 */

#define DP_IRDMA_LA                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0000))                      /* 0x3AC9 */
#define DP_IRDMA_UA                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0001))                      /* 0x3ACA */
#define DP_IRDMA_FB                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0002))                      /* 0x3ACB */
#define DP_IRDMA_SB                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0003))                      /* 0x3ACC */
#define DP_IRDMA_TB                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0004))                      /* 0x3ACD */
#define DP_IRDMA_ENA                        (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0005))                      /* 0x3ACE */
#define DP_BUF_SIZE                         (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0006))                      /* 0x3ACF */
#define DP_SUB_BUF_NUM                      (*(volatile uint16_t *)DPRAM_BASE(DP_IRDMA_BASE + 0x0007))                      /* 0x3AD0 */

#define DP_DEBUG_CTRL_BASE                  (DP_IRDMA_BASE + 0x0008)                                                        /* 0x3AD1 */

#define DP_DB_CNTL                          (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0000))                 /* 0x3AD1 */
#define DP_DB_FLT_MD0                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0001))                 /* 0x3AD2 */
#define DP_DB_FLT_MD1                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0002))                 /* 0x3AD3 */
#define DP_DB_FLT_MD2                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0003))                 /* 0x3AD4 */
#define DP_DB_FLT_MD3                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0004))                 /* 0x3AD5 */
#define DP_DB_FLT_SP                        (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0005))                 /* 0x3AD6 */
#define SPH_IRDBG_FLT                       (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0005))                 /* 0x3AD6 */
#define DP_DB_FLT_AU                        (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0006))                 /* 0x3AD7 */
#define DP_DB_PTR                           (*(volatile uint16_t *)DPRAM_BASE(DP_DEBUG_CTRL_BASE + 0x0007))                 /* 0x3AD8 */

#define DP_MCU_DEBUG_INFO_BASE              (DP_DEBUG_CTRL_BASE + 0x0008)                                                   /* 0x3AD9 */

#define DP_MCU_TQWRAP                       (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0000))             /* 0x3AD9 */
#define DP_MCU_AFC                          (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0001))             /* 0x3ADA */
#define DP_MCU_ARFCN_WIN0                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0002))             /* 0x3ADB */
#define DP_MCU_ARFCN_WIN1                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0003))             /* 0x3ADC */
#define DP_MCU_ARFCN_WIN2                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0004))             /* 0x3ADD */
#define DP_MCU_ARFCN_WIN3                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0005))             /* 0x3ADE */
#define DP_MCU_ARFCN_WIN4                   (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0006))             /* 0x3ADF */
#define DP_MCU_AGC_WIN0                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0007))             /* 0x3AE0 */
#define DP_MCU_AGC_WIN1                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0008))             /* 0x3AE1 */
#define DP_MCU_AGC_WIN2                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x0009))             /* 0x3AE2 */
#define DP_MCU_AGC_WIN3                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x000A))             /* 0x3AE3 */
#define DP_MCU_AGC_WIN4                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x000B))             /* 0x3AE4 */
#define DP_MCU_AGC_WIN5                     (*(volatile uint16_t *)DPRAM_BASE(DP_MCU_DEBUG_INFO_BASE + 0x000C))             /* 0x3AE5 */

#define DP_LOGI_CHANNEL_BASE                (DP_MCU_DEBUG_INFO_BASE + 0x000D)                                               /* 0x3AE6 */

#define DP_GSM_MODE                         (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0000))               /* 0x3AE6 */
#define DP_TCH_S0_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0001))               /* 0x3AE7 */
#define DP_TCH_S1_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0002))               /* 0x3AE8 */
#define DP_TCH_S2_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0003))               /* 0x3AE9 */
#define DP_TCH_S3_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0004))               /* 0x3AEA */
#define DP_TCH_S4_FLAGS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0005))               /* 0x3AEB */
#define DP_SACCH_S0_POS                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0006))               /* 0x3AEC */
#define DP_NB_TSC                           (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0007))               /* 0x3AED */
#define DP2_TX_GPRS_CONSTELLATION0          (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0008))               /* 0x3AEE */
#define DP2_TX_GPRS_CONSTELLATION           (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0008))               /* 0x3AEE */
#define DP2_TX_GPRS_CONSTELLATION1          (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0009))               /* 0x3AEF */
#define DP2_FAST_PCH_ENABLE                 (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000A))               /* 0x3AF0 */
#define DP2_REPEATED_ACCH_GOOD_FLAG         (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000B))               /* 0x3AF1 */
#define DP2_REPEATED_ACCH_ENABLE_FLAG       (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000C))               /* 0x3AF2 */
#define DP2_2ND_CD_ENABLE_FLAGS             (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000D))               /* 0x3AF3 */
#define DP2_2ND_CD_TYPE                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000E))               /* 0x3AF4 */
#define DP2_2ND_CD_LENGHT_INFO              (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x000F))               /* 0x3AF5 */
#define DP2_2ND_CD_GOOD_FLAGS               (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0010))               /* 0x3AF6 */
#define DP2_FACCH_LIKE_THRES                (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0011))               /* 0x3AF7 */
#define DP2_FACCH_LIKE_FLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0012))               /* 0x3AF8 */
#define DP2_FACCH_THRES                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0013))               /* 0x3AF9 */
#define DP2_BFI_MEAN_SNTH                   (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0014))               /* 0x3AFA */
#define DP2_BFI_D_TH                        (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0015))               /* 0x3AFB */
#define DP_BFI_SN_THRES                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0016))               /* 0x3AFC */
#define DP_LP_BACK_MODE                     (*(volatile uint16_t *)DPRAM_BASE(DP_LOGI_CHANNEL_BASE + 0x0017))               /* 0x3AFD */

#define DP_EGPRS_CHANNEL_CODEC_BASE         (DP_LOGI_CHANNEL_BASE + 0x0018)                                                 /* 0x3AFE */

#define DP2_EDGE_S0_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0000))        /* 0x3AFE */
#define DP2_EDGE_S1_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0001))        /* 0x3AFF */
#define DP2_EDGE_S2_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0002))        /* 0x3B00 */
#define DP2_EDGE_S3_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0003))        /* 0x3B01 */
#define DP2_EDGE_S4_MCS                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0004))        /* 0x3B02 */
#define DP2_EDGE_SRB_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0005))        /* 0x3B03 */
#define DP2_IR_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0006))        /* 0x3B04 */
#define DP2_RLC_WIN_SIZE                    (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0007))        /* 0x3B05 */
#define DP2_RLC_VQ                          (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0008))        /* 0x3B06 */
#define DP2_IR_DEC_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x0009))        /* 0x3B07 */
#define DP2_IR_MEM_THRE_HIGH                (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000A))        /* 0x3B08 */
#define DP2_IR_MEM_THRE_LOW                 (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000B))        /* 0x3B09 */
#define DP2_IR_MEM_ADDR_L                   (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000C))        /* 0x3B0A */
#define DP2_IR_MEM_ADDR_H                   (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000D))        /* 0x3B0B */
#define DP2_AVAIL_IR_MEM_BLOCK_NUM          (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000E))        /* 0x3B0C */
#define DP2_IR_MEM_BLOCK_NUM                (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_CHANNEL_CODEC_BASE + 0x000F))        /* 0x3B0D */

#define DP2_PERI_CTRL_BASE                  (DP_EGPRS_CHANNEL_CODEC_BASE + 0x0010)                                          /* 0x3B0E */

#define DP2_PERI_CTRL_CONFIG                (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0000))                 /* 0x3B0E */
#define DP2_PERI_CTRL_DSP_READ1             (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0001))                 /* 0x3B0F */
#define DP2_PERI_CTRL_DSP_WRITE1            (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0002))                 /* 0x3B10 */
#define DP2_PERI_CTRL_DSP_READ2             (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0003))                 /* 0x3B11 */
#define DP2_PERI_CTRL_DSP_WRITE2            (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0004))                 /* 0x3B12 */
#define DP2_PERI_CTRL_DSP_READ3             (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0005))                 /* 0x3B13 */
#define DP2_PERI_CTRL_DSP_WRITE3            (*(volatile uint16_t *)DPRAM_BASE(DP2_PERI_CTRL_BASE + 0x0006))                 /* 0x3B14 */

#define DP2_AMR_CTRL_BASE                   (DP2_PERI_CTRL_BASE + 0x0007)                                                   /* 0x3B15 */

#define DP2_AMR_T1                          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0000))                  /* 0x3B15 */
#define DP2_AMR_T2                          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0001))                  /* 0x3B16 */
#define DP2_AMR_T3                          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0002))                  /* 0x3B17 */
#define DP2_AMR_FLAGS                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0003))                  /* 0x3B18 */
#define DP2_AMR_ICM                         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0004))                  /* 0x3B19 */
#define DP2_AMR_DL_ACS_01                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0005))                  /* 0x3B1A */
#define DP2_AMR_DL_ACS_23                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0006))                  /* 0x3B1B */
#define DP2_AMR_UL_ACS_01                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0007))                  /* 0x3B1C */
#define DP2_AMR_UL_ACS_23                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0008))                  /* 0x3B1D */
#define DP2_AMR_CONFIG_FLAGS                (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x0009))                  /* 0x3B1E */
#define DP2_AMR_CI_COMPEN                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_CTRL_BASE + 0x000A))                  /* 0x3B1F */

#define DP2_VAMOS_AMR_BFI_SAIC_TH_BASE      (DP2_AMR_CTRL_BASE + 0x000B)                                                    /* 0x3B20 */

#define DP2_VAMOS_AMR_BFI_SAIC_TH           (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0000))     /* 0x3B20 */
#define DP2_VAMOS_AMR_BFI_M_DTX_SAIC_0      (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0000))     /* 0x3B20 */
#define DP2_VAMOS_BFI_MODEM_0_SAIC          (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0000))     /* 0x3B20 */
#define DP2_VAMOS_AMR_BFI_M_DTX_SAIC_1      (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0001))     /* 0x3B21 */
#define DP2_VAMOS_BFI_MODEM_1_SAIC          (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0001))     /* 0x3B21 */
#define DP2_VAMOS_AMR_BFI_M_DTX_SAIC_2      (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0002))     /* 0x3B22 */
#define DP2_VAMOS_BFI_SPEECH_0_SAIC         (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0002))     /* 0x3B22 */
#define DP2_VAMOS_AMR_BFI_M_DTX_SAIC_3      (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0003))     /* 0x3B23 */
#define DP2_VAMOS_BFI_SPEECH_1_SAIC         (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0003))     /* 0x3B23 */
#define DP2_VAMOS_AMR_BFI_M_ACTIVE_SAIC_0   (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0004))     /* 0x3B24 */
#define DP2_VAMOS_BFI_UFI_SAIC              (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0004))     /* 0x3B24 */
#define DP2_VAMOS_AMR_BFI_M_ACTIVE_SAIC_1   (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0005))     /* 0x3B25 */
#define DP2_VAMOS_AMR_BFI_M_ACTIVE_SAIC_2   (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0006))     /* 0x3B26 */
#define DP2_VAMOS_AMR_BFI_M_ACTIVE_SAIC_3   (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0007))     /* 0x3B27 */
#define DP2_VAMOS_AMR_BFI_SP_0_SAIC_0       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0008))     /* 0x3B28 */
#define DP2_VAMOS_AMR_BFI_SP_0_SAIC_1       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0009))     /* 0x3B29 */
#define DP2_VAMOS_AMR_BFI_SP_0_SAIC_2       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000A))     /* 0x3B2A */
#define DP2_VAMOS_AMR_BFI_SP_0_SAIC_3       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000B))     /* 0x3B2B */
#define DP2_VAMOS_AMR_BFI_SP_1_SAIC_0       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000C))     /* 0x3B2C */
#define DP2_VAMOS_AMR_BFI_SP_1_SAIC_1       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000D))     /* 0x3B2D */
#define DP2_VAMOS_AMR_BFI_SP_1_SAIC_2       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000E))     /* 0x3B2E */
#define DP2_VAMOS_AMR_BFI_SP_1_SAIC_3       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x000F))     /* 0x3B2F */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_0       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0010))     /* 0x3B30 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_1       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0011))     /* 0x3B31 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_2       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0012))     /* 0x3B32 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_3       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0013))     /* 0x3B33 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_X       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0014))     /* 0x3B34 */
#define DP2_VAMOS_AMR_BFI_SP_2_SAIC_Y       (*(volatile uint16_t *)DPRAM_BASE(DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0015))     /* 0x3B35 */

#define DP2_AMR_BFI_SAIC_TH_BASE            (DP2_VAMOS_AMR_BFI_SAIC_TH_BASE + 0x0016)                                       /* 0x3B36 */

#define DP2_AMR_BFI_SAIC_TH                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0000))           /* 0x3B36 */
#define DP2_AMR_BFI_M_DTX_SAIC_0            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0000))           /* 0x3B36 */
#define DP2_BFI_MODEM_0_SAIC                (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0000))           /* 0x3B36 */
#define DP2_AMR_BFI_M_DTX_SAIC_1            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0001))           /* 0x3B37 */
#define DP2_BFI_MODEM_1_SAIC                (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0001))           /* 0x3B37 */
#define DP2_AMR_BFI_M_DTX_SAIC_2            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0002))           /* 0x3B38 */
#define DP2_BFI_SPEECH_0_SAIC               (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0002))           /* 0x3B38 */
#define DP2_AMR_BFI_M_DTX_SAIC_3            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0003))           /* 0x3B39 */
#define DP2_BFI_SPEECH_1_SAIC               (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0003))           /* 0x3B39 */
#define DP2_AMR_BFI_M_ACTIVE_SAIC_0         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0004))           /* 0x3B3A */
#define DP2_BFI_UFI_SAIC                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0004))           /* 0x3B3A */
#define DP2_AMR_BFI_M_ACTIVE_SAIC_1         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0005))           /* 0x3B3B */
#define DP2_BFI_MODEM_0                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0005))           /* 0x3B3B */
#define DP2_AMR_BFI_M_ACTIVE_SAIC_2         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0006))           /* 0x3B3C */
#define DP2_BFI_MODEM_1                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0006))           /* 0x3B3C */
#define DP2_AMR_BFI_M_ACTIVE_SAIC_3         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0007))           /* 0x3B3D */
#define DP2_BFI_SPEECH_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0007))           /* 0x3B3D */
#define DP2_AMR_BFI_SP_0_SAIC_0             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0008))           /* 0x3B3E */
#define DP2_BFI_SPEECH_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0008))           /* 0x3B3E */
#define DP2_AMR_BFI_SP_0_SAIC_1             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0009))           /* 0x3B3F */
#define DP2_BFI_UFI                         (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0009))           /* 0x3B3F */
#define DP2_AMR_BFI_SP_0_SAIC_2             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000A))           /* 0x3B40 */
#define DP2_AMR_BFI_SP_0_SAIC_3             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000B))           /* 0x3B41 */
#define DP2_AMR_BFI_SP_1_SAIC_0             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000C))           /* 0x3B42 */
#define DP2_AMR_BFI_SP_1_SAIC_1             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000D))           /* 0x3B43 */
#define DP2_AMR_BFI_SP_1_SAIC_2             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000E))           /* 0x3B44 */
#define DP2_AMR_BFI_SP_1_SAIC_3             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x000F))           /* 0x3B45 */
#define DP2_AMR_BFI_SP_2_SAIC_0             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0010))           /* 0x3B46 */
#define DP2_AMR_BFI_SP_2_SAIC_1             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0011))           /* 0x3B47 */
#define DP2_AMR_BFI_SP_2_SAIC_2             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0012))           /* 0x3B48 */
#define DP2_AMR_BFI_SP_2_SAIC_3             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0013))           /* 0x3B49 */
#define DP2_AMR_BFI_SP_2_SAIC_X             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0014))           /* 0x3B4A */
#define DP2_AMR_BFI_SP_2_SAIC_Y             (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_BFI_SAIC_TH_BASE + 0x0015))           /* 0x3B4B */

#define DP2_AMR_THRE_BASE                   (DP2_AMR_BFI_SAIC_TH_BASE + 0x0016)                                             /* 0x3B4C */

#define DP2_AMR_SP_DEGRADE_THRES_0          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_THRE_BASE + 0x0000))                  /* 0x3B4C */
#define DP2_AMR_SP_DEGRADE_THRES_1          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_THRE_BASE + 0x0001))                  /* 0x3B4D */
#define DP2_AMR_SP_DEGRADE_THRES_2          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_THRE_BASE + 0x0002))                  /* 0x3B4E */
#define DP2_AMR_SP_DEGRADE_THRES_3          (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_THRE_BASE + 0x0003))                  /* 0x3B4F */

#define DP_MODEM_CTRL_RESERVED_BASE         (DP2_AMR_THRE_BASE + 0x0004)                                                    /* 0x3B50 */

#define DP_LOW_ANT_PWR_TH                   (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0000))        /* 0x3B50 */
#define DP_HEADROOM_DET_TH                  (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0001))        /* 0x3B51 */
#define DP_GAIN_IMB_IDX                     (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0002))        /* 0x3B52 */
#define DP_OBB_WEIGHT                       (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0003))        /* 0x3B53 */
#define DP_OT_TX_IQMM_ARTIFICIAL_DC         (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0004))        /* 0x3B54 */
#define DP_OT_TX_IQMM_GAIN                  (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0005))        /* 0x3B55 */
#define DP_OT_TX_IQMM_PHASE                 (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_CTRL_RESERVED_BASE + 0x0006))        /* 0x3B56 */

#define DP2_ENCRYPT2_BASE                   (DP_MODEM_CTRL_RESERVED_BASE + 0x0013)                                          /* 0x3B63 */

#define DP2_ENCRYP_KEY_5                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPT2_BASE + 0x0000))                  /* 0x3B63 */
#define DP2_ENCRYP_KEY_6                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPT2_BASE + 0x0001))                  /* 0x3B64 */
#define DP2_ENCRYP_KEY_7                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPT2_BASE + 0x0002))                  /* 0x3B65 */
#define DP2_ENCRYP_KEY_8                    (*(volatile uint16_t *)DPRAM_BASE(DP2_ENCRYPT2_BASE + 0x0003))                  /* 0x3B66 */

#define DP2_AMR_TRACE_BASE                  (DP2_ENCRYPT2_BASE + 0x0004)                                                    /* 0x3B67 */

#define DP2_AMR_USED_CODEC                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0000))                 /* 0x3B67 */
#define DP2_AMR_TRACE_CODEC                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0001))                 /* 0x3B68 */
#define DP2_AMR_TRACE_CC_TX                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0002))                 /* 0x3B69 */
#define DP2_AMR_INB_CORR0                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0003))                 /* 0x3B6A */
#define DP2_AMR_RX_TRACE_01_BASE            (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0003))                 /* 0x3B6A */
#define DP2_AMR_INB_CORR1                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0004))                 /* 0x3B6B */
#define DP2_AMR_INB_CORR2                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0005))                 /* 0x3B6C */
#define DP2_AMR_INB_CORR3                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0006))                 /* 0x3B6D */
#define DP2_AMR_SLRESETFLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0007))                 /* 0x3B6E */
#define DP2_AMR_SP_SC                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0008))                 /* 0x3B6F */
#define DP2_AMR_SP_SD                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x0009))                 /* 0x3B70 */
#define DP2_AMR_EQ_SN_SUM                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AMR_TRACE_BASE + 0x000A))                 /* 0x3B71 */

#define DP_REPORT_BASE                      (DP2_AMR_TRACE_BASE + 0x000B)                                                   /* 0x3B72 */

#define DP_DARP_FOE_Q                       (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0000))                     /* 0x3B72 */
#define DP_EQ_SINR_FWBW_REPLACE_HIT         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0001))                     /* 0x3B73 */
#define DP_EQSO_SUM_LO                      (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0002))                     /* 0x3B74 */
#define DP_EQSO_SUM_HI                      (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0003))                     /* 0x3B75 */
#define DP_CHL_S0                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0004))                     /* 0x3B76 */
#define DP_CHL_S1                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0005))                     /* 0x3B77 */
#define DP_CHL_S2                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0006))                     /* 0x3B78 */
#define DP_CHL_S3                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0007))                     /* 0x3B79 */
#define DP_CHL_S4                           (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0008))                     /* 0x3B7A */
#define DP_CHL_R_S0                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x0009))                     /* 0x3B7B */
#define DP_CHL_R_S1                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x000A))                     /* 0x3B7C */
#define DP_CHL_R_S2                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x000B))                     /* 0x3B7D */
#define DP_CHL_R_S3                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x000C))                     /* 0x3B7E */
#define DP_CHL_R_S4                         (*(volatile uint16_t *)DPRAM_BASE(DP_REPORT_BASE + 0x000D))                     /* 0x3B7F */

#define DP_NB_RESULT_RX0_BASE               (DP_REPORT_BASE + 0x0010)                                                       /* 0x3B82 */

#define DP_NB_RES_S0_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0000))              /* 0x3B82 */
#define DP_TX_IQMM_D_I_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0000))              /* 0x3B82 */
#define DP_NB_RES_S0_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0001))              /* 0x3B83 */
#define DP_TX_IQMM_D_Q_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0001))              /* 0x3B83 */
#define DP_NB_RES_S0_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0002))              /* 0x3B84 */
#define DP_TX_IQMM_V_I_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0002))              /* 0x3B84 */
#define DP_NB_RES_S0_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0003))              /* 0x3B85 */
#define DP_TX_IQMM_V_Q_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0003))              /* 0x3B85 */
#define DP_NB_RES_S0_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0004))              /* 0x3B86 */
#define DP_TX_IQMM_L_I_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0004))              /* 0x3B86 */
#define DP_NB_RES_S0_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0005))              /* 0x3B87 */
#define DP_TX_IQMM_L_Q_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0005))              /* 0x3B87 */
#define DP_NB_RES_S0_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0006))              /* 0x3B88 */
#define DP_NB_RES_S0_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0007))              /* 0x3B89 */
#define DP_NB_RES_S0_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0008))              /* 0x3B8A */
#define DP_DC_PROC_OUT0                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0008))              /* 0x3B8A */
#define DP_NB_RES_S0_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0009))              /* 0x3B8B */
#define DP_DC_PROC_OUT1                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0009))              /* 0x3B8B */
#define DP_NB_RES_S0_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000A))              /* 0x3B8C */
#define DP_DC_PROC_OUT2                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000A))              /* 0x3B8C */
#define DP_NB_RES_S0_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000B))              /* 0x3B8D */
#define DP_NB_RES_S0_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000C))              /* 0x3B8E */
#define DP_NB_RES_S0_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000D))              /* 0x3B8F */
#define DP_NB_RES_S0_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000E))              /* 0x3B90 */
#define DP_NB_RES_S0_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x000F))              /* 0x3B91 */
#define DP_NB_RES_S0_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0010))              /* 0x3B92 */
#define DP_NB_RES_S0_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0011))              /* 0x3B93 */
#define DP_NB_RES_S0_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0012))              /* 0x3B94 */
#define DP_NB_RES_S0_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0013))              /* 0x3B95 */
#define DP_NB_RES_S0_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0014))              /* 0x3B96 */
#define DP_NB_RES_S0_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0015))              /* 0x3B97 */
#define DP_NB_RES_S0_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0016))              /* 0x3B98 */
#define DP_NB_RES_S0_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0017))              /* 0x3B99 */
#define DP_NB_RES_S0_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0018))              /* 0x3B9A */
#define DP_NB_RES_S0_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x0019))              /* 0x3B9B */
#define DP_NB_RES_S0_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001A))              /* 0x3B9C */
#define DP_NB_RES_S0_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001B))              /* 0x3B9D */
#define DP_NB_RES_S0_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001C))              /* 0x3B9E */
#define DP_NB_RES_S0_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001D))              /* 0x3B9F */
#define DP_S0_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001D))              /* 0x3B9F */
#define DP_ENH_MEASURE_REPORT_BASE          (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001D))              /* 0x3B9F */
#define DP_NB_RES_S0_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001E))              /* 0x3BA0 */
#define DP_S0_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX0_BASE + 0x001E))              /* 0x3BA0 */

#define DP_NB_RESULT_RX1_BASE               (DP_NB_RESULT_RX0_BASE + 0x0021)                                                /* 0x3BA3 */

#define DP_NB_RES_S1_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0000))              /* 0x3BA3 */
#define DP_TX_IQMM_D_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0000))              /* 0x3BA3 */
#define DP_NB_RES_S1_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0001))              /* 0x3BA4 */
#define DP_TX_IQMM_D_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0001))              /* 0x3BA4 */
#define DP_NB_RES_S1_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0002))              /* 0x3BA5 */
#define DP_TX_IQMM_V_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0002))              /* 0x3BA5 */
#define DP_NB_RES_S1_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0003))              /* 0x3BA6 */
#define DP_TX_IQMM_V_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0003))              /* 0x3BA6 */
#define DP_NB_RES_S1_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0004))              /* 0x3BA7 */
#define DP_TX_IQMM_L_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0004))              /* 0x3BA7 */
#define DP_NB_RES_S1_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0005))              /* 0x3BA8 */
#define DP_TX_IQMM_L_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0005))              /* 0x3BA8 */
#define DP_NB_RES_S1_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0006))              /* 0x3BA9 */
#define DP_TX_IQMM_T_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0006))              /* 0x3BA9 */
#define DP_NB_RES_S1_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0007))              /* 0x3BAA */
#define DP_TX_IQMM_T_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0007))              /* 0x3BAA */
#define DP_NB_RES_S1_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0008))              /* 0x3BAB */
#define DP_TX_IQMM_GT_S1                    (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0008))              /* 0x3BAB */
#define DP_NB_RES_S1_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0009))              /* 0x3BAC */
#define DP_TX_IQMM_PHIT_S1                  (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0009))              /* 0x3BAC */
#define DP_NB_RES_S1_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000A))              /* 0x3BAD */
#define DP_TX_IQMM_G_I_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000A))              /* 0x3BAD */
#define DP_NB_RES_S1_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000B))              /* 0x3BAE */
#define DP_TX_IQMM_G_Q_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000B))              /* 0x3BAE */
#define DP_NB_RES_S1_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000C))              /* 0x3BAF */
#define DP_TX_IQMM_DC_I_S1                  (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000C))              /* 0x3BAF */
#define DP_NB_RES_S1_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000D))              /* 0x3BB0 */
#define DP_TX_IQMM_DC_Q_S1                  (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000D))              /* 0x3BB0 */
#define DP_NB_RES_S1_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000E))              /* 0x3BB1 */
#define DP_NB_RES_S1_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x000F))              /* 0x3BB2 */
#define DP_NB_RES_S1_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0010))              /* 0x3BB3 */
#define DP_NB_RES_S1_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0011))              /* 0x3BB4 */
#define DP_NB_RES_S1_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0012))              /* 0x3BB5 */
#define DP_NB_RES_S1_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0013))              /* 0x3BB6 */
#define DP_NB_RES_S1_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0014))              /* 0x3BB7 */
#define DP_NB_RES_S1_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0015))              /* 0x3BB8 */
#define DP_NB_RES_S1_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0016))              /* 0x3BB9 */
#define DP_NB_RES_S1_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0017))              /* 0x3BBA */
#define DP_NB_RES_S1_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0018))              /* 0x3BBB */
#define DP_NB_RES_S1_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x0019))              /* 0x3BBC */
#define DP_NB_RES_S1_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001A))              /* 0x3BBD */
#define DP_NB_RES_S1_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001B))              /* 0x3BBE */
#define DP_NB_RES_S1_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001C))              /* 0x3BBF */
#define DP_NB_RES_S1_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001D))              /* 0x3BC0 */
#define DP_S1_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001D))              /* 0x3BC0 */
#define DP_NB_RES_S1_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001E))              /* 0x3BC1 */
#define DP_S1_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX1_BASE + 0x001E))              /* 0x3BC1 */

#define DP_NB_RESULT_RX2_BASE               (DP_NB_RESULT_RX1_BASE + 0x0021)                                                /* 0x3BC4 */

#define DP_NB_RES_S2_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0000))              /* 0x3BC4 */
#define DP_NB_RES_S2_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0001))              /* 0x3BC5 */
#define DP_NB_RES_S2_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0002))              /* 0x3BC6 */
#define DP_NB_RES_S2_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0003))              /* 0x3BC7 */
#define DP_NB_RES_S2_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0004))              /* 0x3BC8 */
#define DP_NB_RES_S2_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0005))              /* 0x3BC9 */
#define DP_NB_RES_S2_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0006))              /* 0x3BCA */
#define DP_NB_RES_S2_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0007))              /* 0x3BCB */
#define DP_NB_RES_S2_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0008))              /* 0x3BCC */
#define DP_NB_RES_S2_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0009))              /* 0x3BCD */
#define DP_NB_RES_S2_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000A))              /* 0x3BCE */
#define DP_NB_RES_S2_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000B))              /* 0x3BCF */
#define DP_NB_RES_S2_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000C))              /* 0x3BD0 */
#define DP_NB_RES_S2_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000D))              /* 0x3BD1 */
#define DP_NB_RES_S2_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000E))              /* 0x3BD2 */
#define DP_NB_RES_S2_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x000F))              /* 0x3BD3 */
#define DP_NB_RES_S2_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0010))              /* 0x3BD4 */
#define DP_NB_RES_S2_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0011))              /* 0x3BD5 */
#define DP_NB_RES_S2_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0012))              /* 0x3BD6 */
#define DP_NB_RES_S2_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0013))              /* 0x3BD7 */
#define DP_NB_RES_S2_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0014))              /* 0x3BD8 */
#define DP_NB_RES_S2_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0015))              /* 0x3BD9 */
#define DP_NB_RES_S2_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0016))              /* 0x3BDA */
#define DP_NB_RES_S2_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0017))              /* 0x3BDB */
#define DP_NB_RES_S2_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0018))              /* 0x3BDC */
#define DP_NB_RES_S2_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x0019))              /* 0x3BDD */
#define DP_NB_RES_S2_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001A))              /* 0x3BDE */
#define DP_NB_RES_S2_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001B))              /* 0x3BDF */
#define DP_NB_RES_S2_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001C))              /* 0x3BE0 */
#define DP_NB_RES_S2_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001D))              /* 0x3BE1 */
#define DP_S2_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001D))              /* 0x3BE1 */
#define DP_NB_RES_S2_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001E))              /* 0x3BE2 */
#define DP_S2_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX2_BASE + 0x001E))              /* 0x3BE2 */

#define DP_NB_RESULT_RX3_BASE               (DP_NB_RESULT_RX2_BASE + 0x0021)                                                /* 0x3BE5 */

#define DP_NB_RES_S3_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0000))              /* 0x3BE5 */
#define DP_NB_RES_S3_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0001))              /* 0x3BE6 */
#define DP_NB_RES_S3_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0002))              /* 0x3BE7 */
#define DP_NB_RES_S3_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0003))              /* 0x3BE8 */
#define DP_NB_RES_S3_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0004))              /* 0x3BE9 */
#define DP_NB_RES_S3_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0005))              /* 0x3BEA */
#define DP_NB_RES_S3_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0006))              /* 0x3BEB */
#define DP_NB_RES_S3_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0007))              /* 0x3BEC */
#define DP_NB_RES_S3_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0008))              /* 0x3BED */
#define DP_NB_RES_S3_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0009))              /* 0x3BEE */
#define DP_NB_RES_S3_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000A))              /* 0x3BEF */
#define DP_NB_RES_S3_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000B))              /* 0x3BF0 */
#define DP_NB_RES_S3_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000C))              /* 0x3BF1 */
#define DP_NB_RES_S3_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000D))              /* 0x3BF2 */
#define DP_NB_RES_S3_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000E))              /* 0x3BF3 */
#define DP_NB_RES_S3_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x000F))              /* 0x3BF4 */
#define DP_NB_RES_S3_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0010))              /* 0x3BF5 */
#define DP_NB_RES_S3_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0011))              /* 0x3BF6 */
#define DP_NB_RES_S3_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0012))              /* 0x3BF7 */
#define DP_NB_RES_S3_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0013))              /* 0x3BF8 */
#define DP_NB_RES_S3_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0014))              /* 0x3BF9 */
#define DP_NB_RES_S3_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0015))              /* 0x3BFA */
#define DP_NB_RES_S3_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0016))              /* 0x3BFB */
#define DP_NB_RES_S3_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0017))              /* 0x3BFC */
#define DP_NB_RES_S3_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0018))              /* 0x3BFD */
#define DP_NB_RES_S3_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x0019))              /* 0x3BFE */
#define DP_NB_RES_S3_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001A))              /* 0x3BFF */
#define DP_NB_RES_S3_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001B))              /* 0x3C00 */
#define DP_NB_RES_S3_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001C))              /* 0x3C01 */
#define DP_NB_RES_S3_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001D))              /* 0x3C02 */
#define DP_S3_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001D))              /* 0x3C02 */
#define DP_NB_RES_S3_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001E))              /* 0x3C03 */
#define DP_S3_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX3_BASE + 0x001E))              /* 0x3C03 */

#define DP_NB_RESULT_RX4_BASE               (DP_NB_RESULT_RX3_BASE + 0x0021)                                                /* 0x3C06 */

#define DP_NB_RES_S4_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0000))              /* 0x3C06 */
#define DP_NB_RES_S4_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0001))              /* 0x3C07 */
#define DP_NB_RES_S4_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0002))              /* 0x3C08 */
#define DP_NB_RES_S4_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0003))              /* 0x3C09 */
#define DP_NB_RES_S4_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0004))              /* 0x3C0A */
#define DP_NB_RES_S4_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0005))              /* 0x3C0B */
#define DP_NB_RES_S4_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0006))              /* 0x3C0C */
#define DP_NB_RES_S4_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0007))              /* 0x3C0D */
#define DP_NB_RES_S4_8                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0008))              /* 0x3C0E */
#define DP_NB_RES_S4_9                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0009))              /* 0x3C0F */
#define DP_NB_RES_S4_10                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000A))              /* 0x3C10 */
#define DP_NB_RES_S4_11                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000B))              /* 0x3C11 */
#define DP_NB_RES_S4_12                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000C))              /* 0x3C12 */
#define DP_NB_RES_S4_13                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000D))              /* 0x3C13 */
#define DP_NB_RES_S4_14                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000E))              /* 0x3C14 */
#define DP_NB_RES_S4_15                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x000F))              /* 0x3C15 */
#define DP_NB_RES_S4_16                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0010))              /* 0x3C16 */
#define DP_NB_RES_S4_17                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0011))              /* 0x3C17 */
#define DP_NB_RES_S4_18                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0012))              /* 0x3C18 */
#define DP_NB_RES_S4_19                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0013))              /* 0x3C19 */
#define DP_NB_RES_S4_20                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0014))              /* 0x3C1A */
#define DP_NB_RES_S4_21                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0015))              /* 0x3C1B */
#define DP_NB_RES_S4_22                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0016))              /* 0x3C1C */
#define DP_NB_RES_S4_23                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0017))              /* 0x3C1D */
#define DP_NB_RES_S4_24                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0018))              /* 0x3C1E */
#define DP_NB_RES_S4_25                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x0019))              /* 0x3C1F */
#define DP_NB_RES_S4_26                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001A))              /* 0x3C20 */
#define DP_NB_RES_S4_27                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001B))              /* 0x3C21 */
#define DP_NB_RES_S4_28                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001C))              /* 0x3C22 */
#define DP_NB_RES_S4_29                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001D))              /* 0x3C23 */
#define DP_S4_MEAN_BEP                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001D))              /* 0x3C23 */
#define DP_NB_RES_S4_30                     (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001E))              /* 0x3C24 */
#define DP_S4_CV_BEP                        (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX4_BASE + 0x001E))              /* 0x3C24 */

#define DP_NB_RESULT_RX5_BASE               (DP_NB_RESULT_RX4_BASE + 0x0021)                                                /* 0x3C27 */

#define DP_NB_RES_S5_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0000))              /* 0x3C27 */
#define DP_NB_RES_S5_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0001))              /* 0x3C28 */
#define DP_NB_RES_S5_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0002))              /* 0x3C29 */
#define DP_NB_RES_S5_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0003))              /* 0x3C2A */
#define DP_NB_RES_S5_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0004))              /* 0x3C2B */
#define DP_NB_RES_S5_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0005))              /* 0x3C2C */
#define DP_NB_RES_S5_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0006))              /* 0x3C2D */
#define DP_NB_RES_S5_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX5_BASE + 0x0007))              /* 0x3C2E */

#define DP_NB_RESULT_RX6_BASE               (DP_NB_RESULT_RX5_BASE + 0x0008)                                                /* 0x3C2F */

#define DP_NB_RES_S6_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0000))              /* 0x3C2F */
#define DP_NB_RES_S6_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0001))              /* 0x3C30 */
#define DP_NB_RES_S6_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0002))              /* 0x3C31 */
#define DP_NB_RES_S6_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0003))              /* 0x3C32 */
#define DP_NB_RES_S6_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0004))              /* 0x3C33 */
#define DP_NB_RES_S6_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0005))              /* 0x3C34 */
#define DP_NB_RES_S6_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0006))              /* 0x3C35 */
#define DP_NB_RES_S6_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX6_BASE + 0x0007))              /* 0x3C36 */

#define DP_NB_RESULT_RX7_BASE               (DP_NB_RESULT_RX6_BASE + 0x0008)                                                /* 0x3C37 */

#define DP_NB_RES_S7_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0000))              /* 0x3C37 */
#define DP_NB_RES_S7_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0001))              /* 0x3C38 */
#define DP_NB_RES_S7_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0002))              /* 0x3C39 */
#define DP_NB_RES_S7_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0003))              /* 0x3C3A */
#define DP_NB_RES_S7_4                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0004))              /* 0x3C3B */
#define DP_NB_RES_S7_5                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0005))              /* 0x3C3C */
#define DP_NB_RES_S7_6                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0006))              /* 0x3C3D */
#define DP_NB_RES_S7_7                      (*(volatile uint16_t *)DPRAM_BASE(DP_NB_RESULT_RX7_BASE + 0x0007))              /* 0x3C3E */

#define DP_SB_RESULT_BASE                   (DP_NB_RESULT_RX7_BASE + 0x0008)                                                /* 0x3C3F */

#define DP_SB_RES_0                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0000))                  /* 0x3C3F */
#define DP_SB_RES_1                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0001))                  /* 0x3C40 */
#define DP_SB_RES_2                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0002))                  /* 0x3C41 */
#define DP_SB_RES_3                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0003))                  /* 0x3C42 */
#define DP_SB_RES_4                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0004))                  /* 0x3C43 */
#define DP_SB_RES_5                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0005))                  /* 0x3C44 */
#define DP_SB_RES_6                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0006))                  /* 0x3C45 */
#define DP_SB_RES_7                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0007))                  /* 0x3C46 */
#define DP_SB_RES_8                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0008))                  /* 0x3C47 */
#define DP_SB_RES_9                         (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x0009))                  /* 0x3C48 */
#define DP_SB_RES_10                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000A))                  /* 0x3C49 */
#define DP_SB_RES_11                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000B))                  /* 0x3C4A */
#define DP_SB_RES_12                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000C))                  /* 0x3C4B */
#define DP_SB_RES_13                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000D))                  /* 0x3C4C */
#define DP_SB_RES_14                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000E))                  /* 0x3C4D */
#define DP_SB_RES_15                        (*(volatile uint16_t *)DPRAM_BASE(DP_SB_RESULT_BASE + 0x000F))                  /* 0x3C4E */

#define DP_FB_RESULT_BASE                   (DP_SB_RESULT_BASE + 0x0011)                                                    /* 0x3C50 */

#define DP_FB_RES_0                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0000))                  /* 0x3C50 */
#define DP_FB_RES_1                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0001))                  /* 0x3C51 */
#define DP_FB_RES_2                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0002))                  /* 0x3C52 */
#define DP_FB_RES_3                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0003))                  /* 0x3C53 */
#define DP_FB_RES_4                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0004))                  /* 0x3C54 */
#define DP_FB_RES_5                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0005))                  /* 0x3C55 */
#define DP_FB_RES_6                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0006))                  /* 0x3C56 */
#define DP_FB_RES_7                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0007))                  /* 0x3C57 */
#define DP_FB_RES_8                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0008))                  /* 0x3C58 */
#define DP_FB_RES_9                         (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x0009))                  /* 0x3C59 */
#define DP_FB_RES_10                        (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x000A))                  /* 0x3C5A */
#define DP_FB_RES_11                        (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x000B))                  /* 0x3C5B */
#define DP_FB_RES_12                        (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x000C))                  /* 0x3C5C */
#define DP_FB_RES_13                        (*(volatile uint16_t *)DPRAM_BASE(DP_FB_RESULT_BASE + 0x000D))                  /* 0x3C5D */

#define DP2_FAST_USF_REPORT_BASE            (DP_FB_RESULT_BASE + 0x0010)                                                    /* 0x3C60 */

#define DP2_CC_USF_S0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0000))           /* 0x3C60 */
#define DP_SF_VALUE                         (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0000))           /* 0x3C60 */
#define DP2_CC_USF_S1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0001))           /* 0x3C61 */
#define DP2_AMR_BFI_TH_BASE                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0001))           /* 0x3C61 */
#define DP2_AMR_BFI_M_DTX_0                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0001))           /* 0x3C61 */
#define DP2_CC_USF_S2                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0002))           /* 0x3C62 */
#define DP2_AMR_BFI_M_DTX_1                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0002))           /* 0x3C62 */
#define DP2_CC_USF_S3                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0003))           /* 0x3C63 */
#define DP2_AMR_BFI_M_DTX_2                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0003))           /* 0x3C63 */
#define DP2_CC_USF_S4                       (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0004))           /* 0x3C64 */
#define DP2_AMR_BFI_M_DTX_3                 (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0004))           /* 0x3C64 */
#define DP2_CC_USF2_S0                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0005))           /* 0x3C65 */
#define DP2_AMR_BFI_M_ACTIVE_0              (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0005))           /* 0x3C65 */
#define DP2_CC_USF2_S1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0006))           /* 0x3C66 */
#define DP2_AMR_BFI_M_ACTIVE_1              (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0006))           /* 0x3C66 */
#define DP2_CC_USF2_S2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0007))           /* 0x3C67 */
#define DP2_AMR_BFI_M_ACTIVE_2              (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0007))           /* 0x3C67 */
#define DP2_CC_USF2_S3                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0008))           /* 0x3C68 */
#define DP2_AMR_BFI_M_ACTIVE_3              (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0008))           /* 0x3C68 */
#define DP2_CC_USF2_S4                      (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0009))           /* 0x3C69 */
#define DP2_AMR_BFI_SP_0_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0009))           /* 0x3C69 */
#define DP2_CC_PRE_USF_S0                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000A))           /* 0x3C6A */
#define DP2_AMR_BFI_SP_0_1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000A))           /* 0x3C6A */
#define DP2_CC_PRE_USF_S1                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000B))           /* 0x3C6B */
#define DP2_AMR_BFI_SP_0_2                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000B))           /* 0x3C6B */
#define DP2_CC_PRE_USF_S2                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000C))           /* 0x3C6C */
#define DP2_AMR_BFI_SP_0_3                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000C))           /* 0x3C6C */
#define DP2_CC_PRE_USF_S3                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000D))           /* 0x3C6D */
#define DP2_AMR_BFI_SP_1_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000D))           /* 0x3C6D */
#define DP2_CC_PRE_USF_S4                   (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000E))           /* 0x3C6E */
#define DP2_AMR_BFI_SP_1_1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000E))           /* 0x3C6E */
#define DP2_CC_PRE_USF2_S0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000F))           /* 0x3C6F */
#define DP2_AMR_BFI_SP_1_2                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x000F))           /* 0x3C6F */
#define DP2_CC_PRE_USF2_S1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0010))           /* 0x3C70 */
#define DP2_AMR_BFI_SP_1_3                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0010))           /* 0x3C70 */
#define DP2_CC_PRE_USF2_S2                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0011))           /* 0x3C71 */
#define DP2_AMR_BFI_SP_2_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0011))           /* 0x3C71 */
#define DP2_CC_PRE_USF2_S3                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0012))           /* 0x3C72 */
#define DP2_AMR_BFI_SP_2_1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0012))           /* 0x3C72 */
#define DP2_CC_PRE_USF2_S4                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0013))           /* 0x3C73 */
#define DP2_AMR_BFI_SP_2_2                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0013))           /* 0x3C73 */
#define DP2_CC_CS_USF_S0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0014))           /* 0x3C74 */
#define DP2_AMR_BFI_SP_2_3                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0014))           /* 0x3C74 */
#define DP2_CC_CS_USF_S1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0015))           /* 0x3C75 */
#define DP2_AMR_BFI_SP_2_X                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0015))           /* 0x3C75 */
#define DP2_CC_CS_USF_S2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0016))           /* 0x3C76 */
#define DP2_AMR_BFI_SP_2_Y                  (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0016))           /* 0x3C76 */
#define DP2_CC_CS_USF_S3                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0017))           /* 0x3C77 */
#define DP2_CC_CS_USF_S4                    (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0018))           /* 0x3C78 */
#define DP2_CC_CS_PRE_USF_S0                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x0019))           /* 0x3C79 */
#define DP2_CC_CS_PRE_USF_S1                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x001A))           /* 0x3C7A */
#define DP2_CC_CS_PRE_USF_S2                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x001B))           /* 0x3C7B */
#define DP2_CC_CS_PRE_USF_S3                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x001C))           /* 0x3C7C */
#define DP2_CC_CS_PRE_USF_S4                (*(volatile uint16_t *)DPRAM_BASE(DP2_FAST_USF_REPORT_BASE + 0x001D))           /* 0x3C7D */

#define DP2_TX_CCCH_BASE                    (DP2_FAST_USF_REPORT_BASE + 0x001E)                                             /* 0x3C7E */

#define DP2_TX_CCCH_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0000))                   /* 0x3C7E */
#define DP2_TX_CCCH_1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0001))                   /* 0x3C7F */
#define DP2_TX_CCCH_2                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0002))                   /* 0x3C80 */
#define DP2_TX_CCCH_3                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0003))                   /* 0x3C81 */
#define DP2_TX_CCCH_4                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0004))                   /* 0x3C82 */
#define DP2_TX_CCCH_5                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0005))                   /* 0x3C83 */
#define DP2_TX_CCCH_6                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0006))                   /* 0x3C84 */
#define DP2_TX_CCCH_7                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0007))                   /* 0x3C85 */
#define DP2_TX_CCCH_8                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0008))                   /* 0x3C86 */
#define DP2_TX_CCCH_9                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x0009))                   /* 0x3C87 */
#define DP2_TX_CCCH_10                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x000A))                   /* 0x3C88 */
#define DP2_TX_CCCH_11                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_CCCH_BASE + 0x000B))                   /* 0x3C89 */

#define DP2_TX_FACCH_BASE                   (DP2_TX_CCCH_BASE + 0x000C)                                                     /* 0x3C8A */

#define DP2_TX_FACCH_0                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0000))                  /* 0x3C8A */
#define DP2_TX_FACCH_1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0001))                  /* 0x3C8B */
#define DP2_TX_FACCH_2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0002))                  /* 0x3C8C */
#define DP2_TX_FACCH_3                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0003))                  /* 0x3C8D */
#define DP2_TX_FACCH_4                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0004))                  /* 0x3C8E */
#define DP2_TX_FACCH_5                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0005))                  /* 0x3C8F */
#define DP2_TX_FACCH_6                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0006))                  /* 0x3C90 */
#define DP2_TX_FACCH_7                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0007))                  /* 0x3C91 */
#define DP2_TX_FACCH_8                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0008))                  /* 0x3C92 */
#define DP2_TX_FACCH_9                      (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x0009))                  /* 0x3C93 */
#define DP2_TX_FACCH_10                     (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x000A))                  /* 0x3C94 */
#define DP2_TX_FACCH_11                     (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_FACCH_BASE + 0x000B))                  /* 0x3C95 */

#define DP2_TX_RACH_BASE                    (DP2_TX_FACCH_BASE + 0x000C)                                                    /* 0x3C96 */

#define DP2_TX_RACH_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RACH_BASE + 0x0000))                   /* 0x3C96 */
#define DP2_TX_RACH_1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RACH_BASE + 0x0001))                   /* 0x3C97 */

#define DP2_TX_RATSCCH_BASE                 (DP2_TX_RACH_BASE + 0x0002)                                                     /* 0x3C98 */

#define DP2_TX_RATSCCH_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RATSCCH_BASE + 0x0000))                /* 0x3C98 */
#define DP2_TX_RATSCCH_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RATSCCH_BASE + 0x0001))                /* 0x3C99 */
#define DP2_TX_RATSCCH_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RATSCCH_BASE + 0x0002))                /* 0x3C9A */
#define DP2_TX_RATSCCH_3                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TX_RATSCCH_BASE + 0x0003))                /* 0x3C9B */

#define DP2_RX_CCCH_PTCCH0_BASE             (DP2_TX_RATSCCH_BASE + 0x0004)                                                  /* 0x3C9C */

#define DP2_RX_PTCCH0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0000))            /* 0x3C9C */
#define DP2_RX_CCCH_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0000))            /* 0x3C9C */
#define DP2_RX_CCCH_1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0001))            /* 0x3C9D */
#define DP2_RX_CCCH_2                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0002))            /* 0x3C9E */
#define DP2_RX_CCCH_3                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0003))            /* 0x3C9F */
#define DP2_RX_CCCH_4                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0004))            /* 0x3CA0 */
#define DP2_RX_CCCH_5                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0005))            /* 0x3CA1 */
#define DP2_RX_CCCH_6                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0006))            /* 0x3CA2 */
#define DP2_RX_CCCH_7                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0007))            /* 0x3CA3 */
#define DP2_RX_CCCH_8                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0008))            /* 0x3CA4 */
#define DP2_RX_CCCH_9                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x0009))            /* 0x3CA5 */
#define DP2_RX_CCCH_10                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x000A))            /* 0x3CA6 */
#define DP2_RX_CCCH_11                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x000B))            /* 0x3CA7 */
#define DP2_RX_CCCH_12                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_CCCH_PTCCH0_BASE + 0x000C))            /* 0x3CA8 */

#define DP2_RX_FACCH_PTCCH1_BASE            (DP2_RX_CCCH_PTCCH0_BASE + 0x000D)                                              /* 0x3CA9 */

#define DP2_RX_PTCCH1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0000))           /* 0x3CA9 */
#define DP2_RX_FACCH_0                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0000))           /* 0x3CA9 */
#define DP2_RX_FACCH_1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0001))           /* 0x3CAA */
#define DP2_RX_FACCH_2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0002))           /* 0x3CAB */
#define DP2_RX_FACCH_3                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0003))           /* 0x3CAC */
#define DP2_RX_FACCH_4                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0004))           /* 0x3CAD */
#define DP2_RX_FACCH_5                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0005))           /* 0x3CAE */
#define DP2_RX_FACCH_6                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0006))           /* 0x3CAF */
#define DP2_RX_FACCH_7                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0007))           /* 0x3CB0 */
#define DP2_RX_FACCH_8                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0008))           /* 0x3CB1 */
#define DP2_RX_FACCH_9                      (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x0009))           /* 0x3CB2 */
#define DP2_RX_FACCH_10                     (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x000A))           /* 0x3CB3 */
#define DP2_RX_FACCH_11                     (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x000B))           /* 0x3CB4 */
#define DP2_RX_FACCH_12                     (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_FACCH_PTCCH1_BASE + 0x000C))           /* 0x3CB5 */

#define DP2_RX_SCH_BASE                     (DP2_RX_FACCH_PTCCH1_BASE + 0x000D)                                             /* 0x3CB6 */

#define DP2_RX_SCH_0                        (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_SCH_BASE + 0x0000))                    /* 0x3CB6 */
#define DP2_RX_SCH_1                        (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_SCH_BASE + 0x0001))                    /* 0x3CB7 */
#define DP2_RX_SCH_2                        (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_SCH_BASE + 0x0002))                    /* 0x3CB8 */
#define DP2_RX_SCH_3                        (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_SCH_BASE + 0x0003))                    /* 0x3CB9 */

#define DP2_RX_RATSCCH_BASE                 (DP2_RX_SCH_BASE + 0x0004)                                                      /* 0x3CBA */

#define DP2_RX_RATSCCH_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_RATSCCH_BASE + 0x0000))                /* 0x3CBA */
#define DP2_RX_RATSCCH_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_RATSCCH_BASE + 0x0001))                /* 0x3CBB */
#define DP2_RX_RATSCCH_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_RATSCCH_BASE + 0x0002))                /* 0x3CBC */
#define DP2_RX_RATSCCH_3                    (*(volatile uint16_t *)DPRAM_BASE(DP2_RX_RATSCCH_BASE + 0x0003))                /* 0x3CBD */

#define DP_TX_TCH_S0_BASE                   (DP2_RX_RATSCCH_BASE + 0x0004)                                                  /* 0x3CBE */

#define DP2_TX_TCH_S0_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0000))                  /* 0x3CBE */
#define DP2_TX_TCH_S0_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0001))                  /* 0x3CBF */
#define DP2_TX_TCH_S0_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0002))                  /* 0x3CC0 */
#define DP2_TX_TCH_S0_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0003))                  /* 0x3CC1 */
#define DP2_TX_TCH_S0_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0004))                  /* 0x3CC2 */
#define DP2_TX_TCH_S0_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0005))                  /* 0x3CC3 */
#define DP2_TX_TCH_S0_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0006))                  /* 0x3CC4 */
#define DP2_TX_TCH_S0_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S0_BASE + 0x0007))                  /* 0x3CC5 */

#define DP_TX_TCH_S1_BASE                   (DP_TX_TCH_S0_BASE + 0x0008)                                                    /* 0x3CC6 */

#define DP2_TX_TCH_S1_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0000))                  /* 0x3CC6 */
#define DP2_BFI_QUAL_0                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0000))                  /* 0x3CC6 */
#define DP2_TX_TCH_S1_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0001))                  /* 0x3CC7 */
#define DP2_BFI_QUAL_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0001))                  /* 0x3CC7 */
#define DP2_TX_TCH_S1_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0002))                  /* 0x3CC8 */
#define DP2_BFI_QUAL_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0002))                  /* 0x3CC8 */
#define DP2_TX_TCH_S1_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0003))                  /* 0x3CC9 */
#define DP2_BFI_QUAL_3                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0003))                  /* 0x3CC9 */
#define DP2_TX_TCH_S1_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0004))                  /* 0x3CCA */
#define DP2_TX_TCH_S1_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0005))                  /* 0x3CCB */
#define DP2_TX_TCH_S1_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0006))                  /* 0x3CCC */
#define DP2_TX_TCH_S1_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S1_BASE + 0x0007))                  /* 0x3CCD */

#define DP_TX_TCH_S2_BASE                   (DP_TX_TCH_S1_BASE + 0x0008)                                                    /* 0x3CCE */

#define DP2_TX_TCH_S2_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0000))                  /* 0x3CCE */
#define DP2_AMR_RX_TRACE_00_BASE            (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0000))                  /* 0x3CCE */
#define DP2_AMR_RX_FLOW_FLAG                (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0000))                  /* 0x3CCE */
#define DP2_TX_TCH_S2_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0001))                  /* 0x3CCF */
#define DP2_AMR_SV_SD_TYPE                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0001))                  /* 0x3CCF */
#define DP2_TX_TCH_S2_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0002))                  /* 0x3CD0 */
#define DP2_AMR_CONFIG_FLAGS_TRACE          (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0002))                  /* 0x3CD0 */
#define DP2_TX_TCH_S2_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0003))                  /* 0x3CD1 */
#define DP2_AMR_IM_DEC                      (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0003))                  /* 0x3CD1 */
#define DP2_TX_TCH_S2_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0004))                  /* 0x3CD2 */
#define DP2_AMR_T2_CD                       (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0004))                  /* 0x3CD2 */
#define DP2_TX_TCH_S2_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0005))                  /* 0x3CD3 */
#define DP2_AMR_BFI                         (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0005))                  /* 0x3CD3 */
#define DP2_TX_TCH_S2_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0006))                  /* 0x3CD4 */
#define DP2_AMR_DL_FACCH                    (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0006))                  /* 0x3CD4 */
#define DP2_TX_TCH_S2_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0007))                  /* 0x3CD5 */
#define DP2_AMR_DL_RATSCCH                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S2_BASE + 0x0007))                  /* 0x3CD5 */

#define DP_TX_TCH_S3_BASE                   (DP_TX_TCH_S2_BASE + 0x0008)                                                    /* 0x3CD6 */

#define DP2_TX_TCH_S3_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0000))                  /* 0x3CD6 */
#define DP2_AMR_TX_TRACE_BASE               (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0000))                  /* 0x3CD6 */
#define DP2_AMR_T2_CE                       (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0000))                  /* 0x3CD6 */
#define DP2_TX_TCH_S3_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0001))                  /* 0x3CD7 */
#define DP2_AMR_UL_FACCH                    (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0001))                  /* 0x3CD7 */
#define DP2_TX_TCH_S3_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0002))                  /* 0x3CD8 */
#define DP2_AMR_UL_RATSCCH                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0002))                  /* 0x3CD8 */
#define DP2_TX_TCH_S3_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0003))                  /* 0x3CD9 */
#define DP2_AMR_S2_SP_FLAG                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0003))                  /* 0x3CD9 */
#define DP2_TX_TCH_S3_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0004))                  /* 0x3CDA */
#define DP2_AMR_SID_STOLEN                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0004))                  /* 0x3CDA */
#define DP2_TX_TCH_S3_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0005))                  /* 0x3CDB */
#define DP2_AMR_SV_SC_TYPE                  (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0005))                  /* 0x3CDB */
#define DP2_TX_TCH_S3_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0006))                  /* 0x3CDC */
#define DP2_AMR_TX_FLOW_FLAG                (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0006))                  /* 0x3CDC */
#define DP2_TX_TCH_S3_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S3_BASE + 0x0007))                  /* 0x3CDD */

#define DP_TX_TCH_S4_BASE                   (DP_TX_TCH_S3_BASE + 0x0008)                                                    /* 0x3CDE */

#define DP2_TX_TCH_S4_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0000))                  /* 0x3CDE */
#define DP2_TX_TCH_S4_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0001))                  /* 0x3CDF */
#define DP2_TX_TCH_S4_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0002))                  /* 0x3CE0 */
#define DP2_TX_TCH_S4_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0003))                  /* 0x3CE1 */
#define DP2_TX_TCH_S4_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0004))                  /* 0x3CE2 */
#define DP2_TX_TCH_S4_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0005))                  /* 0x3CE3 */
#define DP2_TX_TCH_S4_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0006))                  /* 0x3CE4 */
#define DP2_TX_TCH_S4_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_TX_TCH_S4_BASE + 0x0007))                  /* 0x3CE5 */

#define DP_RX_TCH_S0_BASE                   (DP_TX_TCH_S4_BASE + 0x0008)                                                    /* 0x3CE6 */

#define DP2_RX_TCH_S0_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0000))                  /* 0x3CE6 */
#define DP2_RX_TCH_S0_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0001))                  /* 0x3CE7 */
#define DP2_RX_TCH_S0_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0002))                  /* 0x3CE8 */
#define DP2_RX_TCH_S0_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0003))                  /* 0x3CE9 */
#define DP2_RX_TCH_S0_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0004))                  /* 0x3CEA */
#define DP2_RX_TCH_S0_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0005))                  /* 0x3CEB */
#define DP2_RX_TCH_S0_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0006))                  /* 0x3CEC */
#define DP2_RX_TCH_S0_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S0_BASE + 0x0007))                  /* 0x3CED */

#define DP_RX_TCH_S1_BASE                   (DP_RX_TCH_S0_BASE + 0x0008)                                                    /* 0x3CEE */

#define DP2_RX_TCH_S1_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0000))                  /* 0x3CEE */
#define DP2_RX_TCH_S1_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0001))                  /* 0x3CEF */
#define DP2_RX_TCH_S1_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0002))                  /* 0x3CF0 */
#define DP2_RX_TCH_S1_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0003))                  /* 0x3CF1 */
#define DP2_RX_TCH_S1_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0004))                  /* 0x3CF2 */
#define DP2_RX_TCH_S1_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0005))                  /* 0x3CF3 */
#define DP2_RX_TCH_S1_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0006))                  /* 0x3CF4 */
#define DP2_RX_TCH_S1_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S1_BASE + 0x0007))                  /* 0x3CF5 */

#define DP_RX_TCH_S2_BASE                   (DP_RX_TCH_S1_BASE + 0x0008)                                                    /* 0x3CF6 */

#define DP2_RX_TCH_S2_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0000))                  /* 0x3CF6 */
#define DP2_RX_TCH_S2_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0001))                  /* 0x3CF7 */
#define DP2_RX_TCH_S2_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0002))                  /* 0x3CF8 */
#define DP2_RX_TCH_S2_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0003))                  /* 0x3CF9 */
#define DP2_RX_TCH_S2_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0004))                  /* 0x3CFA */
#define DP2_RX_TCH_S2_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0005))                  /* 0x3CFB */
#define DP2_RX_TCH_S2_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0006))                  /* 0x3CFC */
#define DP2_RX_TCH_S2_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S2_BASE + 0x0007))                  /* 0x3CFD */

#define DP_RX_TCH_S3_BASE                   (DP_RX_TCH_S2_BASE + 0x0008)                                                    /* 0x3CFE */

#define DP2_RX_TCH_S3_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0000))                  /* 0x3CFE */
#define DP2_RX_TCH_S3_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0001))                  /* 0x3CFF */
#define DP2_RX_TCH_S3_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0002))                  /* 0x3D00 */
#define DP2_RX_TCH_S3_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0003))                  /* 0x3D01 */
#define DP2_RX_TCH_S3_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0004))                  /* 0x3D02 */
#define DP2_RX_TCH_S3_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0005))                  /* 0x3D03 */
#define DP2_RX_TCH_S3_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0006))                  /* 0x3D04 */
#define DP2_RX_TCH_S3_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S3_BASE + 0x0007))                  /* 0x3D05 */

#define DP_RX_TCH_S4_BASE                   (DP_RX_TCH_S3_BASE + 0x0008)                                                    /* 0x3D06 */

#define DP2_RX_TCH_S4_0                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0000))                  /* 0x3D06 */
#define DP2_RX_TCH_S4_1                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0001))                  /* 0x3D07 */
#define DP2_RX_TCH_S4_2                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0002))                  /* 0x3D08 */
#define DP2_RX_TCH_S4_3                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0003))                  /* 0x3D09 */
#define DP2_RX_TCH_S4_4                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0004))                  /* 0x3D0A */
#define DP2_RX_TCH_S4_5                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0005))                  /* 0x3D0B */
#define DP2_RX_TCH_S4_6                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0006))                  /* 0x3D0C */
#define DP2_RX_TCH_S4_7                     (*(volatile uint16_t *)DPRAM_BASE(DP_RX_TCH_S4_BASE + 0x0007))                  /* 0x3D0D */

#define DP2_TEST_FEATURES_S0_BASE           (DP_RX_TCH_S4_BASE + 0x0008)                                                    /* 0x3D0E */

#define DP2_TX_TEST_S0_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S0_BASE + 0x0000))          /* 0x3D0E */
#define DP2_TX_TEST_S0_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S0_BASE + 0x0001))          /* 0x3D0F */
#define DP2_TX_TEST_S0_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S0_BASE + 0x0002))          /* 0x3D10 */

#define DP2_TEST_FEATURES_S1_BASE           (DP2_TEST_FEATURES_S0_BASE + 0x0003)                                            /* 0x3D11 */

#define DP2_TX_TEST_S1_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S1_BASE + 0x0000))          /* 0x3D11 */
#define DP2_TX_TEST_S1_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S1_BASE + 0x0001))          /* 0x3D12 */
#define DP2_TX_TEST_S1_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S1_BASE + 0x0002))          /* 0x3D13 */

#define DP2_TEST_FEATURES_S2_BASE           (DP2_TEST_FEATURES_S1_BASE + 0x0003)                                            /* 0x3D14 */

#define DP2_TX_TEST_S2_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S2_BASE + 0x0000))          /* 0x3D14 */
#define DP2_TX_TEST_S2_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S2_BASE + 0x0001))          /* 0x3D15 */
#define DP2_TX_TEST_S2_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S2_BASE + 0x0002))          /* 0x3D16 */

#define DP2_TEST_FEATURES_S3_BASE           (DP2_TEST_FEATURES_S2_BASE + 0x0003)                                            /* 0x3D17 */

#define DP2_TX_TEST_S3_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S3_BASE + 0x0000))          /* 0x3D17 */
#define DP2_TX_TEST_S3_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S3_BASE + 0x0001))          /* 0x3D18 */
#define DP2_TX_TEST_S3_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S3_BASE + 0x0002))          /* 0x3D19 */

#define DP2_TEST_FEATURES_S4_BASE           (DP2_TEST_FEATURES_S3_BASE + 0x0003)                                            /* 0x3D1A */

#define DP2_TX_TEST_S4_0                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S4_BASE + 0x0000))          /* 0x3D1A */
#define DP2_TX_TEST_S4_1                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S4_BASE + 0x0001))          /* 0x3D1B */
#define DP2_TX_TEST_S4_2                    (*(volatile uint16_t *)DPRAM_BASE(DP2_TEST_FEATURES_S4_BASE + 0x0002))          /* 0x3D1C */

#define DP_OUTER_REPORT_BASE                (DP2_TEST_FEATURES_S4_BASE + 0x0003)                                            /* 0x3D1D */

#define DP2_BFI_USED_THRES                  (*(volatile uint16_t *)DPRAM_BASE(DP_OUTER_REPORT_BASE + 0x0000))               /* 0x3D1D */
#define DP2_BFI_USED_D                      (*(volatile uint16_t *)DPRAM_BASE(DP_OUTER_REPORT_BASE + 0x0001))               /* 0x3D1E */

#define DP_EGPRS_BITMAP_DEBUG_BASE          (DP_OUTER_REPORT_BASE + 0x0002)                                                 /* 0x3D1F */

#define DP_EGPRS_BITMAP_DEBUG_0             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0000))         /* 0x3D1F */
#define DP_EGPRS_BITMAP_DEBUG_1             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0001))         /* 0x3D20 */
#define DP_EGPRS_BITMAP_DEBUG_2             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0002))         /* 0x3D21 */
#define DP_EGPRS_BITMAP_DEBUG_3             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0003))         /* 0x3D22 */
#define DP_EGPRS_BITMAP_DEBUG_4             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0004))         /* 0x3D23 */
#define DP_EGPRS_BITMAP_DEBUG_5             (*(volatile uint16_t *)DPRAM_BASE(DP_EGPRS_BITMAP_DEBUG_BASE + 0x0005))         /* 0x3D24 */

#define DP_MODEM_RESERVED_BASE              (DP_EGPRS_BITMAP_DEBUG_BASE + 0x0006)                                           /* 0x3D25 */

#define DP_VAMOS_DEBUG_ZETA_EST             (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0000))             /* 0x3D25 */
#define DP_VAMOS_DEBUG_SCORE1               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0001))             /* 0x3D26 */
#define DP_VAMOS_DEBUG_SCORE2               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0002))             /* 0x3D27 */
#define DP_PREV_T2                          (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0003))             /* 0x3D28 */
#define DP_PREV_WIN_PROC_0123               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0004))             /* 0x3D29 */
#define DP_PREV_WIN_PROC_4567               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0005))             /* 0x3D2A */
#define DP_CURR_T2                          (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0006))             /* 0x3D2B */
#define DP_CURR_WIN_PROC_0123               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0007))             /* 0x3D2C */
#define DP_CURR_WIN_PROC_4567               (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0008))             /* 0x3D2D */
#define DP_DIS_EGPRS_REPORT                 (*(volatile uint16_t *)DPRAM_BASE(DP_MODEM_RESERVED_BASE + 0x0009))             /* 0x3D2E */

#define DP2_SP_CODEC_CTRL_BASE              (DP_MODEM_RESERVED_BASE + 0x0047)                                               /* 0x3D6C */

#define DP_SC_ADDR                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0000))             /* 0x3D6C */
#define DP2_SC_FLAGS                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0000))             /* 0x3D6C */
#define SPH_COD_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0000))             /* 0x3D6C */
#define DP2_DEL_PCM_R                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0001))             /* 0x3D6D */
#define SPH_DEL_R                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0001))             /* 0x3D6D */
#define DP2_DEL_PCM_W                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0002))             /* 0x3D6E */
#define SPH_DEL_W                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0002))             /* 0x3D6E */
#define DP_MARGIN_PCM_ADDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0003))             /* 0x3D6F */
#define DP2_MARGIN_PCM_W                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0003))             /* 0x3D6F */
#define SPH_DEL_M                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0003))             /* 0x3D6F */
#define DP2_SC_MODE                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0004))             /* 0x3D70 */
#define SPH_COD_MODE                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0004))             /* 0x3D70 */
#define DP2_SC_VAD                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0005))             /* 0x3D71 */
#define DP2_SC_MUTE                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0006))             /* 0x3D72 */
#define DP2_NSYNC_NOT_ETSI_C                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0006))             /* 0x3D72 */
#define SPH_MUTE_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0006))             /* 0x3D72 */
#define DP2_OFFSET_COUNT                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0007))             /* 0x3D73 */
#define SPH_DEL_O                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0007))             /* 0x3D73 */
#define DP2_NSYNC_VALUE                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CODEC_CTRL_BASE + 0x0008))             /* 0x3D74 */

#define DP2_SP_AUDIO_INTERFACE_CTRL_BASE    (DP2_SP_CODEC_CTRL_BASE + 0x0009)                                               /* 0x3D75 */

#define DP_AUDIO_ADDR                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0000))   /* 0x3D75 */
#define SPH_DL_VOL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0000))   /* 0x3D75 */
#define SPH_8K_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0001))   /* 0x3D76 */
#define AUDIO_PAR                           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0001))   /* 0x3D76 */
#define SPH_UL_BKF_FLT_TAP                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0002))   /* 0x3D77 */
#define SPH_DL_BKF_FLT_TAP                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0004))   /* 0x3D79 */
#define SPH_UL_VOL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0005))   /* 0x3D7A */
#define SPH_ST_VOL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0006))   /* 0x3D7B */
#define AUDIO_ASP_WAV_OUT_GAIN              (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0007))   /* 0x3D7C */
#define SPH_PM_ADDR_BKF_FLT_COEF_UL_NB      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0008))   /* 0x3D7D */
#define SPH_PM_ADDR_BKF_FLT_COEF_DL_NB      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0009))   /* 0x3D7E */
#define SPH_PM_ADDR_BKF_FLT_COEF_UL_WB      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000A))   /* 0x3D7F */
#define SPH_PM_ADDR_BKF_FLT_COEF_DL_WB      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000B))   /* 0x3D80 */
#define SPH_PM_ADDR_ST_FLT_COEF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000C))   /* 0x3D81 */
#define SPH_PM_ADDR_SRC_FLT_COEF            (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000D))   /* 0x3D82 */
#define SPH_DM_ADDR_EMP                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000E))   /* 0x3D83 */
#define DP_BT_EARPHONE_MODE                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000F))   /* 0x3D84 */
#define SPH_BT_MODE                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x000F))   /* 0x3D84 */
#define DP_ADAPTIVE_GAIN_CONTROL            (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0010))   /* 0x3D85 */
#define SPH_ENH_DL_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0010))   /* 0x3D85 */

#define DP2_SP_KT_CTRL_BASE                 (DP2_SP_AUDIO_INTERFACE_CTRL_BASE + 0x0013)                                     /* 0x3D88 */

#define DP_KEYTONE_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0000))                /* 0x3D88 */
#define KEYTONE1_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0000))                /* 0x3D88 */
#define KEYTONE2_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0001))                /* 0x3D89 */
#define DP_ASP_FORCE_KT_8K                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0002))                /* 0x3D8A */
#define KEYTONE1_FREQ1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0003))                /* 0x3D8B */
#define KEYTONE1_FREQ2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0004))                /* 0x3D8C */
#define KEYTONE1_AMP                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0005))                /* 0x3D8D */
#define KEYTONE2_FREQ1                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0006))                /* 0x3D8E */
#define KEYTONE2_FREQ2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0007))                /* 0x3D8F */
#define KEYTONE2_AMP                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0008))                /* 0x3D90 */
#define DP_KEYTONE_ATT_GAIN                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0009))                /* 0x3D91 */
#define KEYTONE_ATT_GAIN_ADDR               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_KT_CTRL_BASE + 0x0009))                /* 0x3D91 */

#define DP2_SP_8KPCM_CTRL_BASE              (DP2_SP_KT_CTRL_BASE + 0x000A)                                                  /* 0x3D92 */

#define DP_ASP_WAV_REC_CTRL                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0000))             /* 0x3D92 */
#define ASP_WAV_REC_CTRL                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0000))             /* 0x3D92 */
#define DP_8KPCM_MIC_REC_IDX                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0001))             /* 0x3D93 */
#define ASP_WAV_REC_IDX                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0001))             /* 0x3D93 */
#define DP_8KPCM_MIC_REC_LEN                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0002))             /* 0x3D94 */
#define ASP_WAV_REC_LEN                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0002))             /* 0x3D94 */
#define DP_8KPCM_SPK_REC_IDX                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0003))             /* 0x3D95 */
#define ASP_DL_WAV_REC_IDX                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0003))             /* 0x3D95 */
#define DP_8KPCM_SPK_REC_LEN                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0004))             /* 0x3D96 */
#define ASP_DL_WAV_REC_LEN                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0004))             /* 0x3D96 */
#define SPH_PCM_REC_CTRL                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0005))             /* 0x3D97 */
#define SPH_DM_ADDR_EPL_UL_PRE_BUF          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0006))             /* 0x3D98 */
#define SPH_DM_ADDR_EPL_UL_POS_BUF          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0007))             /* 0x3D99 */
#define SPH_DM_ADDR_EPL_DL_PRE_BUF          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0008))             /* 0x3D9A */
#define SPH_DM_ADDR_EPL_DL_POS_BUF          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0009))             /* 0x3D9B */
#define SPH_DM_ADDR_SE2_PTR                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000A))             /* 0x3D9C */
#define DP_D2C_SPEECH_UL_INT                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000C))             /* 0x3D9E */
#define DP_D2C_SPEECH_DL_INT                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000D))             /* 0x3D9F */
#define DP_SPH_3G_SYNC_FLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000E))             /* 0x3DA0 */
#define SPH_DM_ADDR_BGS_UL_BUF              (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x000F))             /* 0x3DA1 */
#define SPH_DM_ADDR_BGS_DL_BUF              (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0010))             /* 0x3DA2 */
#define SPH_BGS_LEN_UL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0011))             /* 0x3DA3 */
#define SPH_BGS_LEN_DL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0012))             /* 0x3DA4 */
#define SPH_BGS_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0013))             /* 0x3DA5 */
#define SPH_BGS_MIX                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_8KPCM_CTRL_BASE + 0x0014))             /* 0x3DA6 */

#define DP2_SP_VM_CTRL_BASE                 (DP2_SP_8KPCM_CTRL_BASE + 0x0015)                                               /* 0x3DA7 */

#define DP_AWB_RX_TCH_S0_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0000))                /* 0x3DA7 */
#define SPH_2G_SD_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0000))                /* 0x3DA7 */
#define DP_SD1_VM_1                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0001))                /* 0x3DA8 */
#define SPH_2G_SD_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0001))                /* 0x3DA8 */
#define DP2_AWB_SD_TCH_MOD                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x001F))                /* 0x3DC6 */
#define DP_AWB_TX_TCH_S0_0                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0020))                /* 0x3DC7 */
#define SPH_2G_SE_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0020))                /* 0x3DC7 */
#define DP_SD2_VM_1                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0021))                /* 0x3DC8 */
#define SPH_2G_SE_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0021))                /* 0x3DC8 */
#define DP_ENCODER_USED_MODE                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0042))                /* 0x3DE9 */
#define DP_DECODER_USED_MODE                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0043))                /* 0x3DEA */
#define DP_VM_DBG_INFO                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0044))                /* 0x3DEB */
#define DP_3G_DEBUG_INFO                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x0044))                /* 0x3DEB */
#define SPH_CTM_AMR_REAL_RX_TYPE            (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VM_CTRL_BASE + 0x007C))                /* 0x3E23 */

#define DP2_SP_CTM_BASE                     (DP2_SP_VM_CTRL_BASE + 0x0081)                                                  /* 0x3E28 */

#define SPH_DM_ADDR_PNW_UL1_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0000))                    /* 0x3E28 */
#define SPH_DM_ADDR_PNW_UL2_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0001))                    /* 0x3E29 */
#define SPH_DM_ADDR_PNW_DL1_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0002))                    /* 0x3E2A */
#define SPH_DM_ADDR_PNW_DL2_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0003))                    /* 0x3E2B */
#define SPH_PNW_CTRL_UL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0004))                    /* 0x3E2C */
#define SPH_PNW_CTRL_DL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0005))                    /* 0x3E2D */
#define SPH_CTM_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0006))                    /* 0x3E2E */
#define SPH_CTM_BFI_FACCH_REPORT            (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0007))                    /* 0x3E2F */
#define SPH_PNW_LEN_UL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0008))                    /* 0x3E30 */
#define SPH_PNW_LEN_DL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x0009))                    /* 0x3E31 */
#define SPH_CTM_AMR_CODEBOOK_GAIN_LIMIT     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x000A))                    /* 0x3E32 */
#define SPH_CTM_AMR_CODEBOOK_GAIN_UPDATE    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x000B))                    /* 0x3E33 */
#define SPH_CTM_COSIM_CTRL                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_CTM_BASE + 0x000C))                    /* 0x3E34 */

#define DP2_SP_AEC_CTRL_BASE                (DP2_SP_CTM_BASE + 0x000D)                                                      /* 0x3E35 */

#define DP_EC_CTRL_ADDR                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0000))               /* 0x3E35 */
#define DP2_EC_SUPP                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0000))               /* 0x3E35 */
#define SPH_ENH_UL_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0000))               /* 0x3E35 */
#define DP_AEC_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0001))               /* 0x3E36 */
#define DP_TDNC_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0001))               /* 0x3E36 */
#define DP_EES_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0002))               /* 0x3E37 */
#define DP_DMNR_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0003))               /* 0x3E38 */
#define DP_AEC_CONTROL_WORD                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0004))               /* 0x3E39 */
#define DP_EC_PAR_ADDR                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0007))               /* 0x3E3C */
#define DP2_ES_TIME_CONST                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0007))               /* 0x3E3C */
#define DP2_ES_VOL_CONST                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AEC_CTRL_BASE + 0x0008))               /* 0x3E3D */

#define DP2_SP_VR_CTRL_BASE                 (DP2_SP_AEC_CTRL_BASE + 0x000F)                                                 /* 0x3E44 */

#define DP_VR_CTRL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VR_CTRL_BASE + 0x0000))                /* 0x3E44 */
#define DP_VR_IO_BASE                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VR_CTRL_BASE + 0x0001))                /* 0x3E45 */
#define DP2_DATA_AP_DATA_UL                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VR_CTRL_BASE + 0x0004))                /* 0x3E48 */
#define DP2_DATA_AP_DATA_DL                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_VR_CTRL_BASE + 0x0005))                /* 0x3E49 */

#define DP2_SP_AUDIO_CTRL_BASE              (DP2_SP_VR_CTRL_BASE + 0x000E)                                                  /* 0x3E52 */

#define DP_TEST_SIM_SBSD_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0000))             /* 0x3E52 */
#define DP2_TEST_SIM_IND                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0000))             /* 0x3E52 */
#define AWB_LB_CHECKSUM_ADDR                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0001))             /* 0x3E53 */
#define AFE_BT_LB_CHECKSUM_ADDR             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0001))             /* 0x3E53 */
#define SPE_RAM_LB_CHECK_ADDR               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0001))             /* 0x3E53 */
#define DP_AUDIO_CTRL2                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0002))             /* 0x3E54 */
#define DP_ENHANCED_AUDIO_CTRL              (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0003))             /* 0x3E55 */
#define SPH_SCH_IMPROVE_CTRL                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0005))             /* 0x3E57 */
#define SPH_BGS_UL_GAIN                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0006))             /* 0x3E58 */
#define SPH_BGS_DL_GAIN                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0007))             /* 0x3E59 */
#define SPH_3G_SE_RATE_UPDATE               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0008))             /* 0x3E5A */
#define SPH_3G_SD_RATE_UPDATE               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x0009))             /* 0x3E5B */
#define DP_AWB_SE_CTRL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000A))             /* 0x3E5C */
#define DP_AWB_SE_STATUS                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000A))             /* 0x3E5C */
#define DP_AWB_SD_CTRL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000B))             /* 0x3E5D */
#define DP_AWB_SD_STATUS                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000B))             /* 0x3E5D */
#define DP_G723_SE_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000C))             /* 0x3E5E */
#define DP_G723_SD_CTRL                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000D))             /* 0x3E5F */
#define DP_NR_CTRL                          (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_CTRL_BASE + 0x000E))             /* 0x3E60 */

#define DP2_SP_AUDIO_ENHANCE_BASE           (DP2_SP_AUDIO_CTRL_BASE + 0x000F)                                               /* 0x3E61 */

#define DP_DSP_DEAD_INT                     (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0000))          /* 0x3E61 */
#define DP_AMR_MODE_ERROR_ASSERT_TYPE       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0001))          /* 0x3E62 */
#define DP_AMR_MODE_ERROR_ASSERT_FLAG       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0002))          /* 0x3E63 */
#define DP_AUDIO_FLEXI_CTRL                 (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0003))          /* 0x3E64 */
#define DP_VOICE_CHG_SCH                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0004))          /* 0x3E65 */
#define DP_VOICE_CHG_TYPE                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0005))          /* 0x3E66 */
#define DP_BT_EARPHONE_UL_CONTROL           (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0006))          /* 0x3E67 */
#define SPH_BT_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0006))          /* 0x3E67 */
#define SPH_DM_ADDR_SE_PTR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0007))          /* 0x3E68 */
#define SPH_DM_ADDR_SD_PTR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0008))          /* 0x3E69 */
#define DP_UP_DOWN_SAMPL_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0009))          /* 0x3E6A */
#define DP_DL_NR_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000A))          /* 0x3E6B */
#define DP_AUDIO_DAC_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000B))          /* 0x3E6C */
#define DP_VBI_SYNC_BT_EARPHONE_CTRL        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000C))          /* 0x3E6D */
#define DP_SBSD_THRESHOLD                   (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000D))          /* 0x3E6E */
#define DP2_8K_SP_CTRL                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000F))          /* 0x3E70 */
#define SPH_SFE_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x000F))          /* 0x3E70 */
#define DP2_AUDIO_VIA_BT_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0010))          /* 0x3E71 */
#define DP2_AUDIO_VIA_BT_INT                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0011))          /* 0x3E72 */
#define DP2_AGC_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0012))          /* 0x3E73 */
#define DP2_AGC_GAIN                        (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0013))          /* 0x3E74 */
#define DP2_DATA_AP_CTRL                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0014))          /* 0x3E75 */
#define DP2_20MS_SP_CTRL                    (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0015))          /* 0x3E76 */
#define DP2_COMPEN_BLOCK_FILTER             (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0015))          /* 0x3E76 */
#define DP_605_TASK_ID                      (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0016))          /* 0x3E77 */
#define DP_605_NO_8K_TASK_ID                (*(volatile uint16_t *)DPRAM_BASE(DP2_SP_AUDIO_ENHANCE_BASE + 0x0017))          /* 0x3E78 */

#define DP2_RESERVE_BASE                    (DP2_SP_AUDIO_ENHANCE_BASE + 0x0018)                                            /* 0x3E79 */

#define SPH_3G_CTRL                         (*(volatile uint16_t *)DPRAM_BASE(DP2_RESERVE_BASE + 0x0000))                   /* 0x3E79 */
#define DP2_DDL_MCU_DSP_HAND_SHAKE          (*(volatile uint16_t *)DPRAM_BASE(DP2_RESERVE_BASE + 0x0001))                   /* 0x3E7A */

#define DP2_AWB_8K_BASE                     (DP2_RESERVE_BASE + 0x0002)                                                     /* 0x3E7B */

#define DP2_RINI_INT                        (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_8K_BASE + 0x0006))                    /* 0x3E81 */
#define DP2_DL_RIN_SIG_ENERGY               (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_8K_BASE + 0x0007))                    /* 0x3E82 */
#define SPH_DYNA_FWLA_MODE_CTRL             (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_8K_BASE + 0x0008))                    /* 0x3E83 */

#define DP2_EPL_BND_BASE                    (DP2_AWB_8K_BASE + 0x0009)                                                      /* 0x3E84 */

#define SPH_EPL_BND                         (*(volatile uint16_t *)DPRAM_BASE(DP2_EPL_BND_BASE + 0x0000))                   /* 0x3E84 */

#define DP2_AWB_LINK_EXTEND_BASE            (DP2_EPL_BND_BASE + 0x0001)                                                     /* 0x3E85 */

#define DP_SD1_AWB_VM_0                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0000))           /* 0x3E85 */
#define DP_3G_RX_VM_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0000))           /* 0x3E85 */
#define SPH_3G_SD_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0000))           /* 0x3E85 */
#define SPH_AP_SD_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0000))           /* 0x3E85 */
#define DP_ORG_SD1_VM_1                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0001))           /* 0x3E86 */
#define SPH_3G_SD_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0001))           /* 0x3E86 */
#define SPH_AP_SD_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0001))           /* 0x3E86 */
#define DP_SD2_AWB_VM_0                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0020))           /* 0x3EA5 */
#define DP_3G_TX_VM_0                       (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0020))           /* 0x3EA5 */
#define SPH_3G_SE_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0020))           /* 0x3EA5 */
#define SPH_AP_SE_DATA_HDR                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0020))           /* 0x3EA5 */
#define DP_ORG_SD2_VM_1                     (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0021))           /* 0x3EA6 */
#define SPH_3G_SE_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0021))           /* 0x3EA6 */
#define SPH_AP_SE_DATA_HB                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0021))           /* 0x3EA6 */
#define DP_SD2_AWB_VM_18                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0032))           /* 0x3EB7 */
#define DP_WB_DEBUG_INFO                    (*(volatile uint16_t *)DPRAM_BASE(DP2_AWB_LINK_EXTEND_BASE + 0x0040))           /* 0x3EC5 */

#define DP_SPEECH_OTHER_BASE                (DP2_AWB_LINK_EXTEND_BASE + 0x004C)                                             /* 0x3ED1 */

#define DP_UL_COMFORT_NOISE_THRESHOLD       (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0000))               /* 0x3ED1 */
#define DP_UL_COMFORT_NOISE_SHIFT           (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0001))               /* 0x3ED2 */
#define DP_DTX_DSPK_FUN_CTRL_ADDR           (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0002))               /* 0x3ED3 */
#define DP_HR_BER_THD_ADDR                  (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0003))               /* 0x3ED4 */
#define DP_FR_BER_THD_ADDR                  (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0004))               /* 0x3ED5 */
#define DP_EFR_BER_THD_ADDR                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0005))               /* 0x3ED6 */
#define DP2_TIME_STAMP_2G_H                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0006))               /* 0x3ED7 */
#define DP2_TIME_STAMP_2G_L                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0007))               /* 0x3ED8 */
#define DP2_TIME_STAMP_3G_H                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0008))               /* 0x3ED9 */
#define DP2_TIME_STAMP_3G_L                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x0009))               /* 0x3EDA */
#define DP2_SPEECH_DEBUG_MODE               (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000A))               /* 0x3EDB */
#define SPH_DBG_MOD                         (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000A))               /* 0x3EDB */
#define DP2_ABF_CTRL_1                      (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000B))               /* 0x3EDC */
#define DP2_ABF_CTRL_2                      (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000C))               /* 0x3EDD */
#define SPH_DUMIC_CTRL                      (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_OTHER_BASE + 0x000D))               /* 0x3EDE */

#define DP_SPEECH_RESERVED_BASE             (DP_SPEECH_OTHER_BASE + 0x000E)                                                 /* 0x3EDF */

#define DP_SPH_COSIM_RESULT_REPORT          (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0000))            /* 0x3EDF */
#define DP_SPH_COSIM_FAIL_TYPE              (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0001))            /* 0x3EE0 */
#define DP_SPH_SPECIAL_LOOPBACK_CTRL        (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0002))            /* 0x3EE1 */
#define DP_TASK5_COSIM_HANDSHAKE            (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0003))            /* 0x3EE2 */
#define DP_AGC_SW_GAIN1                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0004))            /* 0x3EE3 */
#define DP_AGC_SW_GAIN2                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0005))            /* 0x3EE4 */
#define SPH_DACA_CTRL                       (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0006))            /* 0x3EE5 */
#define SPH_DM_ADDR_DACA_UL_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0007))            /* 0x3EE6 */
#define SPH_DM_ADDR_DACA_DL_BUF             (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0008))            /* 0x3EE7 */
#define SPH_DACA_LEN_UL                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0009))            /* 0x3EE8 */
#define SPH_DACA_LEN_DL                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000A))            /* 0x3EE9 */
#define SPH_SW_TRANSC_SD_CNTR               (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000B))            /* 0x3EEA */
#define SPH_SW_TRANSC_TAF_CNTR              (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000C))            /* 0x3EEB */
#define SPH_APP_MODE                        (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000D))            /* 0x3EEC */
#define SPH_VOLTE_JBM_CTRL                  (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000E))            /* 0x3EED */
#define SPH_PCM_FRM_PEAK_UL                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x000F))            /* 0x3EEE */
#define SPH_PCM_FRM_PEAK_DL                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0010))            /* 0x3EEF */
#define SPH_WARN_MSG_UL                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0011))            /* 0x3EF0 */
#define SPH_WARN_MSG_DL                     (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0012))            /* 0x3EF1 */
#define SPH_8K_RESYNC_CTRL                  (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0013))            /* 0x3EF2 */
#define SPH_8K_RESYNC_OFFSET_UL             (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0014))            /* 0x3EF3 */
#define SPH_8K_RESYNC_OFFSET_DL             (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0015))            /* 0x3EF4 */
#define SPH_8K_DIS_VBI_CTRL                 (*(volatile uint16_t *)DPRAM_BASE(DP_SPEECH_RESERVED_BASE + 0x0016))            /* 0x3EF5 */

#define DP2_AUDIO_CTRL_FIELD_BASE           (DP_SPEECH_RESERVED_BASE + 0x0019)                                              /* 0x3EF8 */

#define DP_AUDIO_ASP_TYPE_ADDR              (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0000))          /* 0x3EF8 */
#define DP_AUDIO_ASP_FS_ADDR                (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0001))          /* 0x3EF9 */
#define DP_AUDIO_ASP_DEL_W_ADDR             (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0002))          /* 0x3EFA */
#define DP_AUDIO_DEC_FRAME_LENGTH           (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0003))          /* 0x3EFB */
#define DP_AUDIO_ASP_DEL_MARGIN_W_ADDR      (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0004))          /* 0x3EFC */
#define DP_VOL_OUT                          (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_CTRL_FIELD_BASE + 0x0005))          /* 0x3EFD */

#define A2V_BASE                            (DP2_AUDIO_CTRL_FIELD_BASE + 0x0006)                                            /* 0x3EFE */

#define A2V_INT_ENABLE                      (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0000))                           /* 0x3EFE */
#define A2V_INT_CNT                         (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0001))                           /* 0x3EFF */
#define A2V_INT_STAMP                       (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0002))                           /* 0x3F00 */
#define A2V_AUDIO_FRMAE_COUNT               (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0003))                           /* 0x3F01 */
#define A2V_VIDEO_FRAME_COUNT               (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0004))                           /* 0x3F02 */
#define A2V_INT_DSP_COUNT                   (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0005))                           /* 0x3F03 */
#define A2V_INTERRUPT_PADDING_FLAG          (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0006))                           /* 0x3F04 */
#define A2V_SPEECH_COUNT                    (*(volatile uint16_t *)DPRAM_BASE(A2V_BASE + 0x0007))                           /* 0x3F05 */

#define DP2_WAV_CTRL_FIELD_BASE             (A2V_BASE + 0x0008)                                                             /* 0x3F06 */

#define DP_ASP_WAV_BASE_CTRL                (*(volatile uint16_t *)DPRAM_BASE(DP2_WAV_CTRL_FIELD_BASE + 0x0000))            /* 0x3F06 */
#define DP_ASP_WAV_W_IO_ADDR                (*(volatile uint16_t *)DPRAM_BASE(DP2_WAV_CTRL_FIELD_BASE + 0x0001))            /* 0x3F07 */
#define DP_ASP_WAV_R_IO_ADDR                (*(volatile uint16_t *)DPRAM_BASE(DP2_WAV_CTRL_FIELD_BASE + 0x0002))            /* 0x3F08 */
#define DP2_WAV_STEREO_FLAG                 (*(volatile uint16_t *)DPRAM_BASE(DP2_WAV_CTRL_FIELD_BASE + 0x0003))            /* 0x3F09 */

#define DP2_WT_CTRL_FIELD_BASE              (DP2_WAV_CTRL_FIELD_BASE + 0x0004)                                              /* 0x3F0A */

#define DP_WT_CONTROL                       (*(volatile uint16_t *)DPRAM_BASE(DP2_WT_CTRL_FIELD_BASE + 0x0000))             /* 0x3F0A */

#define DP2_MP3_CTRL_FIELD_BASE             (DP2_WT_CTRL_FIELD_BASE + 0x0001)                                               /* 0x3F0B */

#define MP3_CONTROL_BASE_ADD                (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0000))            /* 0x3F0B */
#define MP3_CONTROL_1                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0001))            /* 0x3F0C */
#define MP3_CONTROL_2                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0002))            /* 0x3F0D */
#define MP3_CONTROL_3                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0003))            /* 0x3F0E */
#define MP3_CONTROL_4                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0004))            /* 0x3F0F */
#define MP3_CONTROL_5                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0005))            /* 0x3F10 */
#define MP3_CONTROL_6                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0006))            /* 0x3F11 */
#define MP3_CONTROL_7                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0007))            /* 0x3F12 */
#define MP3_CONTROL_8                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0008))            /* 0x3F13 */
#define MP3_CONTROL_9                       (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0009))            /* 0x3F14 */
#define MP3_CONTROL_10                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000A))            /* 0x3F15 */
#define MP3_CONTROL_11                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000B))            /* 0x3F16 */
#define MP3_CONTROL_12                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000C))            /* 0x3F17 */
#define MP3_CONTROL_13                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000D))            /* 0x3F18 */
#define MP3_CONTROL_14                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000E))            /* 0x3F19 */
#define MP3_CONTROL_15                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x000F))            /* 0x3F1A */
#define MP3_CONTROL_16                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0010))            /* 0x3F1B */
#define MP3_CONTROL_17                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0011))            /* 0x3F1C */
#define MP3_CONTROL_18                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0012))            /* 0x3F1D */
#define MP3_CONTROL_19                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0013))            /* 0x3F1E */
#define MP3_CONTROL_20                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0014))            /* 0x3F1F */
#define MP3_CONTROL_21                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0015))            /* 0x3F20 */
#define MP3_CONTROL_22                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0016))            /* 0x3F21 */
#define MP3_CONTROL_23                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0017))            /* 0x3F22 */
#define MP3_CONTROL_24                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0018))            /* 0x3F23 */
#define MP3_CONTROL_25                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x0019))            /* 0x3F24 */
#define MP3_CONTROL_26                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x001A))            /* 0x3F25 */
#define MP3_CONTROL_27                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x001B))            /* 0x3F26 */
#define MP3_CONTROL_28                      (*(volatile uint16_t *)DPRAM_BASE(DP2_MP3_CTRL_FIELD_BASE + 0x001C))            /* 0x3F27 */

#define DP2_AUDIO_PP_CTRL_BASE              (DP2_MP3_CTRL_FIELD_BASE + 0x001D)                                              /* 0x3F28 */

#define DP2_AUDIO_PP_CTRL                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0000))             /* 0x3F28 */
#define DP_AUDIO_GAIN_STEP                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0001))             /* 0x3F29 */
#define AUDIO_PP_TS_SPEED                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0002))             /* 0x3F2A */
#define AUDIO_PP_RESERVEA1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0003))             /* 0x3F2B */
#define AUDIO_DEBUG_SHERIF1                 (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0003))             /* 0x3F2B */
#define AUDIO_PP_TS_APM_TO_DSP_LENGTH       (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0004))             /* 0x3F2C */
#define AUD_VSG_CTRL                        (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0005))             /* 0x3F2D */
#define VS_MOD_FREQ                         (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0006))             /* 0x3F2E */
#define VS_CENTER_FREQ                      (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0007))             /* 0x3F2F */
#define VS_DIGI_GAIN                        (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0008))             /* 0x3F30 */
#define AUDIO_PP_RESERVEA6                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0009))             /* 0x3F31 */
#define AUDIO_PP_RESERVEA7                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000A))             /* 0x3F32 */
#define DP_AUDIO_DEC_CNTR_THRESHOLD         (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000B))             /* 0x3F33 */
#define DP_AUDIO_CUR_GAIN                   (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000C))             /* 0x3F34 */
#define AUDIO_CHECK_ASP_TYPE                (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000D))             /* 0x3F35 */
#define PCM_ROUNT_DATA_ADDRESS              (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000E))             /* 0x3F36 */
#define PCM_ROUNT_DATA_LENGTH               (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x000F))             /* 0x3F37 */
#define PCM_ROUNT_DATA_PAGENUM              (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0010))             /* 0x3F38 */
#define AUDIO_PP_RESERVEC1                  (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0011))             /* 0x3F39 */
#define AUDIO_32K_RECORD_CTRL               (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0012))             /* 0x3F3A */
#define DYNAMIC_DOWNLOAD_MCU_STATUS         (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0013))             /* 0x3F3B */
#define DYNAMIC_DOWNLOAD_STATUS             (*(volatile uint16_t *)DPRAM_BASE(DP2_AUDIO_PP_CTRL_BASE + 0x0014))             /* 0x3F3C */

#define DP2_EXTRA_APPLICATION_FILED_BASE    (DP2_AUDIO_PP_CTRL_BASE + 0x0015)                                               /* 0x3F3D */

#define DP_AUDIO_ASP_COMMON_FLAG_1          (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0000))   /* 0x3F3D */
#define AUDIO_RAMPDOWN_ENABLE               (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0001))   /* 0x3F3E */
#define AUDIO_SD_ISR_CYCLE                  (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0002))   /* 0x3F3F */
#define DP_AUDIO_ASP_COMMON_FLAG_2          (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0003))   /* 0x3F40 */
#define DP_AUDIO_ASP_D2M_COUNT              (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0004))   /* 0x3F41 */
#define DP_TASK4_COSIM_HANDSHAKE            (*(volatile uint16_t *)DPRAM_BASE(DP2_EXTRA_APPLICATION_FILED_BASE + 0x0005))   /* 0x3F42 */

#define DP2_DYNAMIC_LOAD_FIELD_BASE         (DP2_EXTRA_APPLICATION_FILED_BASE + 0x0006)                                     /* 0x3F43 */

#define DDL_TASK_FLAG                       (*(volatile uint16_t *)DPRAM_BASE(DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0000))        /* 0x3F43 */
#define DP2_DYNAMIC_LOAD_FIELD              (*(volatile uint16_t *)DPRAM_BASE(DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0000))        /* 0x3F43 */
#define DDL_CHECK_POSITION                  (*(volatile uint16_t *)DPRAM_BASE(DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0001))        /* 0x3F44 */
#define DDL_TASK_ID                         (*(volatile uint16_t *)DPRAM_BASE(DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0002))        /* 0x3F45 */

#define DP2_AUDIO_RESERVED_BASE             (DP2_DYNAMIC_LOAD_FIELD_BASE + 0x0003)                                          /* 0x3F46 */

#define DP2_AUDIO_RESERVED_BASE1            (DP2_AUDIO_RESERVED_BASE + 0x0000)                                              /* 0x3F46 */
#define DP2_AUDIO_RESERVED_BASE2            (DP2_AUDIO_RESERVED_BASE + 0x0001)                                              /* 0x3F47 */

#define DP2_UNDEFINEDD_BASE                 (DP2_AUDIO_RESERVED_BASE + 0x0002)                                              /* 0x3F48 */

#endif /* _DPRAM_H_ */
