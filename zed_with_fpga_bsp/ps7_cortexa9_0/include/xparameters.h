#ifndef XPARAMETERS_H   /* prevent circular inclusions */
#define XPARAMETERS_H   /* by using protection macros */

/* Definition for CPU ID */
#define XPAR_CPU_ID 0U

/* Definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_PS7_CORTEXA9_0_CPU_CLK_FREQ_HZ 666666687


/******************************************************************/

/* Canonical definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ 666666687


/******************************************************************/

#include "xparameters_ps.h"

#define STDIN_BASEADDRESS 0xE0001000
#define STDOUT_BASEADDRESS 0xE0001000

/******************************************************************/

/* Platform specific definitions */
#define PLATFORM_ZYNQ
 
/* Definitions for sleep timer configuration */
#define XSLEEP_TIMER_IS_DEFAULT_TIMER
 
 
/******************************************************************/
/* Definitions for driver AXIVDMA */
#define XPAR_XAXIVDMA_NUM_INSTANCES 1U

/* Definitions for peripheral AXI_HDMI_DMA */
#define XPAR_AXI_HDMI_DMA_DEVICE_ID 0U
#define XPAR_AXI_HDMI_DMA_BASEADDR 0x43000000U
#define XPAR_AXI_HDMI_DMA_HIGHADDR 0x43000FFFU
#define XPAR_AXI_HDMI_DMA_NUM_FSTORES 3U
#define XPAR_AXI_HDMI_DMA_INCLUDE_MM2S 1U
#define XPAR_AXI_HDMI_DMA_INCLUDE_MM2S_DRE 0U
#define XPAR_AXI_HDMI_DMA_M_AXI_MM2S_DATA_WIDTH 64U
#define XPAR_AXI_HDMI_DMA_INCLUDE_S2MM 0U
#define XPAR_AXI_HDMI_DMA_INCLUDE_S2MM_DRE 0U
#define XPAR_AXI_HDMI_DMA_M_AXI_S2MM_DATA_WIDTH 64U
#define XPAR_AXI_HDMI_DMA_AXI_MM2S_ACLK_FREQ_HZ 0U
#define XPAR_AXI_HDMI_DMA_AXI_S2MM_ACLK_FREQ_HZ 0U
#define XPAR_AXI_HDMI_DMA_MM2S_GENLOCK_MODE 3U
#define XPAR_AXI_HDMI_DMA_MM2S_GENLOCK_NUM_MASTERS 1U
#define XPAR_AXI_HDMI_DMA_S2MM_GENLOCK_MODE 0U
#define XPAR_AXI_HDMI_DMA_S2MM_GENLOCK_NUM_MASTERS 1U
#define XPAR_AXI_HDMI_DMA_INCLUDE_SG 0U
#define XPAR_AXI_HDMI_DMA_ENABLE_VIDPRMTR_READS 1U
#define XPAR_AXI_HDMI_DMA_USE_FSYNC 1U
#define XPAR_AXI_HDMI_DMA_FLUSH_ON_FSYNC 1U
#define XPAR_AXI_HDMI_DMA_MM2S_LINEBUFFER_DEPTH 512U
#define XPAR_AXI_HDMI_DMA_S2MM_LINEBUFFER_DEPTH 512U
#define XPAR_AXI_HDMI_DMA_INCLUDE_INTERNAL_GENLOCK 1U
#define XPAR_AXI_HDMI_DMA_S2MM_SOF_ENABLE 1U
#define XPAR_AXI_HDMI_DMA_M_AXIS_MM2S_TDATA_WIDTH 64U
#define XPAR_AXI_HDMI_DMA_S_AXIS_S2MM_TDATA_WIDTH 32U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_INFO_1 0U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_INFO_5 0U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_INFO_6 1U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_INFO_7 1U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_INFO_9 0U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_INFO_13 0U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_INFO_14 1U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_INFO_15 1U
#define XPAR_AXI_HDMI_DMA_ENABLE_DEBUG_ALL 0U
#define XPAR_AXI_HDMI_DMA_ADDR_WIDTH 32U
#define XPAR_AXI_HDMI_DMA_ENABLE_VERT_FLIP 0U


/******************************************************************/

/* Canonical definitions for peripheral AXI_HDMI_DMA */
#define XPAR_AXIVDMA_0_DEVICE_ID XPAR_AXI_HDMI_DMA_DEVICE_ID
#define XPAR_AXIVDMA_0_BASEADDR 0x43000000U
#define XPAR_AXIVDMA_0_HIGHADDR 0x43000FFFU
#define XPAR_AXIVDMA_0_NUM_FSTORES 3U
#define XPAR_AXIVDMA_0_INCLUDE_MM2S 1U
#define XPAR_AXIVDMA_0_INCLUDE_MM2S_DRE 0U
#define XPAR_AXIVDMA_0_M_AXI_MM2S_DATA_WIDTH 64U
#define XPAR_AXIVDMA_0_INCLUDE_S2MM 0U
#define XPAR_AXIVDMA_0_INCLUDE_S2MM_DRE 0U
#define XPAR_AXIVDMA_0_M_AXI_S2MM_DATA_WIDTH 64U
#define XPAR_AXIVDMA_0_AXI_MM2S_ACLK_FREQ_HZ 0U
#define XPAR_AXIVDMA_0_AXI_S2MM_ACLK_FREQ_HZ 0U
#define XPAR_AXIVDMA_0_MM2S_GENLOCK_MODE 3U
#define XPAR_AXIVDMA_0_MM2S_GENLOCK_NUM_MASTERS 1U
#define XPAR_AXIVDMA_0_S2MM_GENLOCK_MODE 0U
#define XPAR_AXIVDMA_0_S2MM_GENLOCK_NUM_MASTERS 1U
#define XPAR_AXIVDMA_0_INCLUDE_SG 0U
#define XPAR_AXIVDMA_0_ENABLE_VIDPRMTR_READS 1U
#define XPAR_AXIVDMA_0_USE_FSYNC 1U
#define XPAR_AXIVDMA_0_FLUSH_ON_FSYNC 1U
#define XPAR_AXIVDMA_0_MM2S_LINEBUFFER_DEPTH 512U
#define XPAR_AXIVDMA_0_S2MM_LINEBUFFER_DEPTH 512U
#define XPAR_AXIVDMA_0_INCLUDE_INTERNAL_GENLOCK 1U
#define XPAR_AXIVDMA_0_S2MM_SOF_ENABLE 1U
#define XPAR_AXIVDMA_0_M_AXIS_MM2S_TDATA_WIDTH 64U
#define XPAR_AXIVDMA_0_S_AXIS_S2MM_TDATA_WIDTH 32U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_1 0U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_5 0U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_6 1U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_7 1U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_9 0U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_13 0U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_14 1U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_INFO_15 1U
#define XPAR_AXIVDMA_0_ENABLE_DEBUG_ALL 0U
#define XPAR_AXIVDMA_0_c_addr_width 32U
#define XPAR_AXIVDMA_0_c_enable_vert_flip 0U


/******************************************************************/


/* Definitions for peripheral PS7_DDR_0 */
#define XPAR_PS7_DDR_0_S_AXI_BASEADDR 0x00100000
#define XPAR_PS7_DDR_0_S_AXI_HIGHADDR 0x1FFFFFFF


/******************************************************************/

/* Definitions for driver DEVCFG */
#define XPAR_XDCFG_NUM_INSTANCES 1U

/* Definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_PS7_DEV_CFG_0_DEVICE_ID 0U
#define XPAR_PS7_DEV_CFG_0_BASEADDR 0xF8007000U
#define XPAR_PS7_DEV_CFG_0_HIGHADDR 0xF80070FFU


/******************************************************************/

/* Canonical definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_XDCFG_0_DEVICE_ID XPAR_PS7_DEV_CFG_0_DEVICE_ID
#define XPAR_XDCFG_0_BASEADDR 0xF8007000U
#define XPAR_XDCFG_0_HIGHADDR 0xF80070FFU


/******************************************************************/

/* Definitions for driver DMAPS */
#define XPAR_XDMAPS_NUM_INSTANCES 2

/* Definitions for peripheral PS7_DMA_NS */
#define XPAR_PS7_DMA_NS_DEVICE_ID 0
#define XPAR_PS7_DMA_NS_BASEADDR 0xF8004000
#define XPAR_PS7_DMA_NS_HIGHADDR 0xF8004FFF


/* Definitions for peripheral PS7_DMA_S */
#define XPAR_PS7_DMA_S_DEVICE_ID 1
#define XPAR_PS7_DMA_S_BASEADDR 0xF8003000
#define XPAR_PS7_DMA_S_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_DMA_NS */
#define XPAR_XDMAPS_0_DEVICE_ID XPAR_PS7_DMA_NS_DEVICE_ID
#define XPAR_XDMAPS_0_BASEADDR 0xF8004000
#define XPAR_XDMAPS_0_HIGHADDR 0xF8004FFF

/* Canonical definitions for peripheral PS7_DMA_S */
#define XPAR_XDMAPS_1_DEVICE_ID XPAR_PS7_DMA_S_DEVICE_ID
#define XPAR_XDMAPS_1_BASEADDR 0xF8003000
#define XPAR_XDMAPS_1_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Definitions for driver EMACPS */
#define XPAR_XEMACPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_PS7_ETHERNET_0_DEVICE_ID 0
#define XPAR_PS7_ETHERNET_0_BASEADDR 0xE000B000
#define XPAR_PS7_ETHERNET_0_HIGHADDR 0xE000BFFF
#define XPAR_PS7_ETHERNET_0_ENET_CLK_FREQ_HZ 125000000
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_1000MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_1000MBPS_DIV1 1
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_100MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_100MBPS_DIV1 5
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_10MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_10MBPS_DIV1 50
#define XPAR_PS7_ETHERNET_0_ENET_TSU_CLK_FREQ_HZ 0


/******************************************************************/

#define XPAR_PS7_ETHERNET_0_IS_CACHE_COHERENT 0
#define XPAR_XEMACPS_0_IS_CACHE_COHERENT 0
/* Canonical definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_XEMACPS_0_DEVICE_ID XPAR_PS7_ETHERNET_0_DEVICE_ID
#define XPAR_XEMACPS_0_BASEADDR 0xE000B000
#define XPAR_XEMACPS_0_HIGHADDR 0xE000BFFF
#define XPAR_XEMACPS_0_ENET_CLK_FREQ_HZ 125000000
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV1 1
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV1 5
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV1 50
#define XPAR_XEMACPS_0_ENET_TSU_CLK_FREQ_HZ 0


/******************************************************************/


/* Definitions for peripheral AXI_HDMI_CLKGEN */
#define XPAR_AXI_HDMI_CLKGEN_BASEADDR 0x79000000
#define XPAR_AXI_HDMI_CLKGEN_HIGHADDR 0x7900FFFF


/* Definitions for peripheral AXI_HDMI_CORE */
#define XPAR_AXI_HDMI_CORE_BASEADDR 0x70E00000
#define XPAR_AXI_HDMI_CORE_HIGHADDR 0x70E0FFFF


/* Definitions for peripheral AXI_HDMI_RX_CORE */
#define XPAR_AXI_HDMI_RX_CORE_BASEADDR 0x43100000
#define XPAR_AXI_HDMI_RX_CORE_HIGHADDR 0x4310FFFF


/* Definitions for peripheral AXI_HDMI_RX_DMA */
#define XPAR_AXI_HDMI_RX_DMA_BASEADDR 0x43C20000
#define XPAR_AXI_HDMI_RX_DMA_HIGHADDR 0x43C20FFF


/* Definitions for peripheral AXI_I2S_ADI */
#define XPAR_AXI_I2S_ADI_BASEADDR 0x77600000
#define XPAR_AXI_I2S_ADI_HIGHADDR 0x7760FFFF


/* Definitions for peripheral AXI_SPDIF_RX_CORE */
#define XPAR_AXI_SPDIF_RX_CORE_BASEADDR 0x75C20000
#define XPAR_AXI_SPDIF_RX_CORE_HIGHADDR 0x75C2FFFF


/* Definitions for peripheral AXI_SPDIF_TX_CORE */
#define XPAR_AXI_SPDIF_TX_CORE_BASEADDR 0x75C00000
#define XPAR_AXI_SPDIF_TX_CORE_HIGHADDR 0x75C0FFFF


/* Definitions for peripheral MUX0 */
#define XPAR_MUX0_BASEADDR 0x41260000
#define XPAR_MUX0_HIGHADDR 0x4126FFFF


/* Definitions for peripheral MUX1 */
#define XPAR_MUX1_BASEADDR 0x41270000
#define XPAR_MUX1_HIGHADDR 0x4127FFFF


/* Definitions for peripheral PS7_AFI_0 */
#define XPAR_PS7_AFI_0_S_AXI_BASEADDR 0xF8008000
#define XPAR_PS7_AFI_0_S_AXI_HIGHADDR 0xF8008FFF


/* Definitions for peripheral PS7_AFI_1 */
#define XPAR_PS7_AFI_1_S_AXI_BASEADDR 0xF8009000
#define XPAR_PS7_AFI_1_S_AXI_HIGHADDR 0xF8009FFF


/* Definitions for peripheral PS7_AFI_2 */
#define XPAR_PS7_AFI_2_S_AXI_BASEADDR 0xF800A000
#define XPAR_PS7_AFI_2_S_AXI_HIGHADDR 0xF800AFFF


/* Definitions for peripheral PS7_AFI_3 */
#define XPAR_PS7_AFI_3_S_AXI_BASEADDR 0xF800B000
#define XPAR_PS7_AFI_3_S_AXI_HIGHADDR 0xF800BFFF


/* Definitions for peripheral PS7_DDRC_0 */
#define XPAR_PS7_DDRC_0_S_AXI_BASEADDR 0xF8006000
#define XPAR_PS7_DDRC_0_S_AXI_HIGHADDR 0xF8006FFF


/* Definitions for peripheral PS7_GLOBALTIMER_0 */
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_BASEADDR 0xF8F00200
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_HIGHADDR 0xF8F002FF


/* Definitions for peripheral PS7_GPV_0 */
#define XPAR_PS7_GPV_0_S_AXI_BASEADDR 0xF8900000
#define XPAR_PS7_GPV_0_S_AXI_HIGHADDR 0xF89FFFFF


/* Definitions for peripheral PS7_INTC_DIST_0 */
#define XPAR_PS7_INTC_DIST_0_S_AXI_BASEADDR 0xF8F01000
#define XPAR_PS7_INTC_DIST_0_S_AXI_HIGHADDR 0xF8F01FFF


/* Definitions for peripheral PS7_IOP_BUS_CONFIG_0 */
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_BASEADDR 0xE0200000
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_HIGHADDR 0xE0200FFF


/* Definitions for peripheral PS7_L2CACHEC_0 */
#define XPAR_PS7_L2CACHEC_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_L2CACHEC_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_OCMC_0 */
#define XPAR_PS7_OCMC_0_S_AXI_BASEADDR 0xF800C000
#define XPAR_PS7_OCMC_0_S_AXI_HIGHADDR 0xF800CFFF


/* Definitions for peripheral PS7_PL310_0 */
#define XPAR_PS7_PL310_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_PL310_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_PMU_0 */
#define XPAR_PS7_PMU_0_S_AXI_BASEADDR 0xF8891000
#define XPAR_PS7_PMU_0_S_AXI_HIGHADDR 0xF8891FFF
#define XPAR_PS7_PMU_0_PMU1_S_AXI_BASEADDR 0xF8893000
#define XPAR_PS7_PMU_0_PMU1_S_AXI_HIGHADDR 0xF8893FFF


/* Definitions for peripheral PS7_QSPI_LINEAR_0 */
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_BASEADDR 0xFC000000
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_HIGHADDR 0xFCFFFFFF


/* Definitions for peripheral PS7_RAM_0 */
#define XPAR_PS7_RAM_0_S_AXI_BASEADDR 0x00000000
#define XPAR_PS7_RAM_0_S_AXI_HIGHADDR 0x0003FFFF


/* Definitions for peripheral PS7_RAM_1 */
#define XPAR_PS7_RAM_1_S_AXI_BASEADDR 0xFFFC0000
#define XPAR_PS7_RAM_1_S_AXI_HIGHADDR 0xFFFFFFFF


/* Definitions for peripheral PS7_SCUC_0 */
#define XPAR_PS7_SCUC_0_S_AXI_BASEADDR 0xF8F00000
#define XPAR_PS7_SCUC_0_S_AXI_HIGHADDR 0xF8F000FC


/* Definitions for peripheral PS7_SLCR_0 */
#define XPAR_PS7_SLCR_0_S_AXI_BASEADDR 0xF8000000
#define XPAR_PS7_SLCR_0_S_AXI_HIGHADDR 0xF8000FFF


/******************************************************************/

/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 4

/* Definitions for peripheral BTN_GPIO */
#define XPAR_BTN_GPIO_BASEADDR 0x41220000
#define XPAR_BTN_GPIO_HIGHADDR 0x41220FFF
#define XPAR_BTN_GPIO_DEVICE_ID 0
#define XPAR_BTN_GPIO_INTERRUPT_PRESENT 1
#define XPAR_BTN_GPIO_IS_DUAL 0


/* Definitions for peripheral DIPSW_GPIO */
#define XPAR_DIPSW_GPIO_BASEADDR 0x41210000
#define XPAR_DIPSW_GPIO_HIGHADDR 0x41210FFF
#define XPAR_DIPSW_GPIO_DEVICE_ID 1
#define XPAR_DIPSW_GPIO_INTERRUPT_PRESENT 1
#define XPAR_DIPSW_GPIO_IS_DUAL 0


/* Definitions for peripheral LED_GPIO */
#define XPAR_LED_GPIO_BASEADDR 0x41200000
#define XPAR_LED_GPIO_HIGHADDR 0x41200FFF
#define XPAR_LED_GPIO_DEVICE_ID 2
#define XPAR_LED_GPIO_INTERRUPT_PRESENT 0
#define XPAR_LED_GPIO_IS_DUAL 1


/* Definitions for peripheral PMOD_GPIO */
#define XPAR_PMOD_GPIO_BASEADDR 0x411F0000
#define XPAR_PMOD_GPIO_HIGHADDR 0x411F0FFF
#define XPAR_PMOD_GPIO_DEVICE_ID 3
#define XPAR_PMOD_GPIO_INTERRUPT_PRESENT 1
#define XPAR_PMOD_GPIO_IS_DUAL 0


/******************************************************************/

/* Canonical definitions for peripheral BTN_GPIO */
#define XPAR_GPIO_0_BASEADDR 0x41220000
#define XPAR_GPIO_0_HIGHADDR 0x41220FFF
#define XPAR_GPIO_0_DEVICE_ID XPAR_BTN_GPIO_DEVICE_ID
#define XPAR_GPIO_0_INTERRUPT_PRESENT 1
#define XPAR_GPIO_0_IS_DUAL 0

/* Canonical definitions for peripheral DIPSW_GPIO */
#define XPAR_GPIO_1_BASEADDR 0x41210000
#define XPAR_GPIO_1_HIGHADDR 0x41210FFF
#define XPAR_GPIO_1_DEVICE_ID XPAR_DIPSW_GPIO_DEVICE_ID
#define XPAR_GPIO_1_INTERRUPT_PRESENT 1
#define XPAR_GPIO_1_IS_DUAL 0

/* Canonical definitions for peripheral LED_GPIO */
#define XPAR_GPIO_2_BASEADDR 0x41200000
#define XPAR_GPIO_2_HIGHADDR 0x41200FFF
#define XPAR_GPIO_2_DEVICE_ID XPAR_LED_GPIO_DEVICE_ID
#define XPAR_GPIO_2_INTERRUPT_PRESENT 0
#define XPAR_GPIO_2_IS_DUAL 1

/* Canonical definitions for peripheral PMOD_GPIO */
#define XPAR_GPIO_3_BASEADDR 0x411F0000
#define XPAR_GPIO_3_HIGHADDR 0x411F0FFF
#define XPAR_GPIO_3_DEVICE_ID XPAR_PMOD_GPIO_DEVICE_ID
#define XPAR_GPIO_3_INTERRUPT_PRESENT 1
#define XPAR_GPIO_3_IS_DUAL 0


/******************************************************************/

/* Definitions for driver GPIOPS */
#define XPAR_XGPIOPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_GPIO_0 */
#define XPAR_PS7_GPIO_0_DEVICE_ID 0
#define XPAR_PS7_GPIO_0_BASEADDR 0xE000A000
#define XPAR_PS7_GPIO_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_GPIO_0 */
#define XPAR_XGPIOPS_0_DEVICE_ID XPAR_PS7_GPIO_0_DEVICE_ID
#define XPAR_XGPIOPS_0_BASEADDR 0xE000A000
#define XPAR_XGPIOPS_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Definitions for driver IIC */
#define XPAR_XIIC_NUM_INSTANCES 4

/* Definitions for peripheral AXI_IIC_EXT */
#define XPAR_AXI_IIC_EXT_DEVICE_ID 0
#define XPAR_AXI_IIC_EXT_BASEADDR 0x41640000
#define XPAR_AXI_IIC_EXT_HIGHADDR 0x41640FFF
#define XPAR_AXI_IIC_EXT_TEN_BIT_ADR 0
#define XPAR_AXI_IIC_EXT_GPO_WIDTH 1


/* Definitions for peripheral AXI_IIC_FMC */
#define XPAR_AXI_IIC_FMC_DEVICE_ID 1
#define XPAR_AXI_IIC_FMC_BASEADDR 0x41620000
#define XPAR_AXI_IIC_FMC_HIGHADDR 0x41620FFF
#define XPAR_AXI_IIC_FMC_TEN_BIT_ADR 0
#define XPAR_AXI_IIC_FMC_GPO_WIDTH 1


/* Definitions for peripheral AXI_IIC_IMAGEON */
#define XPAR_AXI_IIC_IMAGEON_DEVICE_ID 2
#define XPAR_AXI_IIC_IMAGEON_BASEADDR 0x43C40000
#define XPAR_AXI_IIC_IMAGEON_HIGHADDR 0x43C40FFF
#define XPAR_AXI_IIC_IMAGEON_TEN_BIT_ADR 0
#define XPAR_AXI_IIC_IMAGEON_GPO_WIDTH 1


/* Definitions for peripheral AXI_IIC_MAIN */
#define XPAR_AXI_IIC_MAIN_DEVICE_ID 3
#define XPAR_AXI_IIC_MAIN_BASEADDR 0x41600000
#define XPAR_AXI_IIC_MAIN_HIGHADDR 0x41600FFF
#define XPAR_AXI_IIC_MAIN_TEN_BIT_ADR 0
#define XPAR_AXI_IIC_MAIN_GPO_WIDTH 1


/******************************************************************/

/* Canonical definitions for peripheral AXI_IIC_EXT */
#define XPAR_IIC_0_DEVICE_ID XPAR_AXI_IIC_EXT_DEVICE_ID
#define XPAR_IIC_0_BASEADDR 0x41640000
#define XPAR_IIC_0_HIGHADDR 0x41640FFF
#define XPAR_IIC_0_TEN_BIT_ADR 0
#define XPAR_IIC_0_GPO_WIDTH 1

/* Canonical definitions for peripheral AXI_IIC_FMC */
#define XPAR_IIC_1_DEVICE_ID XPAR_AXI_IIC_FMC_DEVICE_ID
#define XPAR_IIC_1_BASEADDR 0x41620000
#define XPAR_IIC_1_HIGHADDR 0x41620FFF
#define XPAR_IIC_1_TEN_BIT_ADR 0
#define XPAR_IIC_1_GPO_WIDTH 1

/* Canonical definitions for peripheral AXI_IIC_IMAGEON */
#define XPAR_IIC_2_DEVICE_ID XPAR_AXI_IIC_IMAGEON_DEVICE_ID
#define XPAR_IIC_2_BASEADDR 0x43C40000
#define XPAR_IIC_2_HIGHADDR 0x43C40FFF
#define XPAR_IIC_2_TEN_BIT_ADR 0
#define XPAR_IIC_2_GPO_WIDTH 1

/* Canonical definitions for peripheral AXI_IIC_MAIN */
#define XPAR_IIC_3_DEVICE_ID XPAR_AXI_IIC_MAIN_DEVICE_ID
#define XPAR_IIC_3_BASEADDR 0x41600000
#define XPAR_IIC_3_HIGHADDR 0x41600FFF
#define XPAR_IIC_3_TEN_BIT_ADR 0
#define XPAR_IIC_3_GPO_WIDTH 1


/******************************************************************/

/* Definitions for driver LLFIFO */
#define XPAR_XLLFIFO_NUM_INSTANCES 1U

/* Definitions for peripheral I2S_FIFO */
#define XPAR_I2S_FIFO_DEVICE_ID 0U
#define XPAR_I2S_FIFO_BASEADDR 0x41630000U
#define XPAR_I2S_FIFO_HIGHADDR 0x41630FFFU
#define XPAR_I2S_FIFO_AXI4_BASEADDR 0U
#define XPAR_I2S_FIFO_AXI4_HIGHADDR 0U
#define XPAR_I2S_FIFO_DATA_INTERFACE_TYPE 0U

/* Canonical definitions for peripheral I2S_FIFO */
#define XPAR_AXI_FIFO_0_DEVICE_ID 0U
#define XPAR_AXI_FIFO_0_BASEADDR 0x41630000U
#define XPAR_AXI_FIFO_0_HIGHADDR 0x41630FFFU
#define XPAR_AXI_FIFO_0_AXI4_BASEADDR 0U
#define XPAR_AXI_FIFO_0_AXI4_HIGHADDR 0U
#define XPAR_AXI_FIFO_0_DATA_INTERFACE_TYPE 0U



/******************************************************************/

/* Definitions for driver QSPIPS */
#define XPAR_XQSPIPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_QSPI_0 */
#define XPAR_PS7_QSPI_0_DEVICE_ID 0
#define XPAR_PS7_QSPI_0_BASEADDR 0xE000D000
#define XPAR_PS7_QSPI_0_HIGHADDR 0xE000DFFF
#define XPAR_PS7_QSPI_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_PS7_QSPI_0_QSPI_MODE 0
#define XPAR_PS7_QSPI_0_QSPI_BUS_WIDTH 2


/******************************************************************/

/* Canonical definitions for peripheral PS7_QSPI_0 */
#define XPAR_XQSPIPS_0_DEVICE_ID XPAR_PS7_QSPI_0_DEVICE_ID
#define XPAR_XQSPIPS_0_BASEADDR 0xE000D000
#define XPAR_XQSPIPS_0_HIGHADDR 0xE000DFFF
#define XPAR_XQSPIPS_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_XQSPIPS_0_QSPI_MODE 0
#define XPAR_XQSPIPS_0_QSPI_BUS_WIDTH 2


/******************************************************************/

/* Definitions for Fabric interrupts connected to ps7_scugic_0 */
#define XPAR_FABRIC_DIPSW_GPIO_IP2INTC_IRPT_INTR 91U
#define XPAR_FABRIC_BTN_GPIO_IP2INTC_IRPT_INTR 90U
#define XPAR_FABRIC_I2S_FIFO_INTERRUPT_INTR 89U
#define XPAR_FABRIC_OLED_SPI_IP2INTC_IRPT_INTR 88U
#define XPAR_FABRIC_TMR2_INTERRUPT_INTR 87U
#define XPAR_FABRIC_TMR3_INTERRUPT_INTR 86U
#define XPAR_FABRIC_PMOD_GPIO_IP2INTC_IRPT_INTR 85U
#define XPAR_FABRIC_UART0_INTERRUPT_INTR 84U
#define XPAR_FABRIC_XADC0_IP2INTC_IRPT_INTR 68U
#define XPAR_FABRIC_AXI_IIC_IMAGEON_IIC2INTC_IRPT_INTR 67U
#define XPAR_FABRIC_AXI_IIC_FMC_IIC2INTC_IRPT_INTR 66U
#define XPAR_FABRIC_AXI_HDMI_RX_DMA_IRQ_INTR 65U
#define XPAR_FABRIC_AXI_IIC_EXT_IIC2INTC_IRPT_INTR 64U
#define XPAR_FABRIC_AXI_IIC_MAIN_IIC2INTC_IRPT_INTR 63U
#define XPAR_FABRIC_AXI_HDMI_DMA_MM2S_INTROUT_INTR 62U

/******************************************************************/

/* Canonical definitions for Fabric interrupts connected to ps7_scugic_0 */
#define XPAR_FABRIC_GPIO_1_VEC_ID XPAR_FABRIC_DIPSW_GPIO_IP2INTC_IRPT_INTR
#define XPAR_FABRIC_GPIO_0_VEC_ID XPAR_FABRIC_BTN_GPIO_IP2INTC_IRPT_INTR
#define XPAR_FABRIC_LLFIFO_0_VEC_ID XPAR_FABRIC_I2S_FIFO_INTERRUPT_INTR
#define XPAR_FABRIC_SPI_0_VEC_ID XPAR_FABRIC_OLED_SPI_IP2INTC_IRPT_INTR
#define XPAR_FABRIC_TMRCTR_2_VEC_ID XPAR_FABRIC_TMR2_INTERRUPT_INTR
#define XPAR_FABRIC_TMRCTR_3_VEC_ID XPAR_FABRIC_TMR3_INTERRUPT_INTR
#define XPAR_FABRIC_GPIO_3_VEC_ID XPAR_FABRIC_PMOD_GPIO_IP2INTC_IRPT_INTR
#define XPAR_FABRIC_UARTLITE_0_VEC_ID XPAR_FABRIC_UART0_INTERRUPT_INTR
#define XPAR_FABRIC_SYSMON_0_VEC_ID XPAR_FABRIC_XADC0_IP2INTC_IRPT_INTR
#define XPAR_FABRIC_IIC_2_VEC_ID XPAR_FABRIC_AXI_IIC_IMAGEON_IIC2INTC_IRPT_INTR
#define XPAR_FABRIC_IIC_1_VEC_ID XPAR_FABRIC_AXI_IIC_FMC_IIC2INTC_IRPT_INTR
#define XPAR_FABRIC_IIC_0_VEC_ID XPAR_FABRIC_AXI_IIC_EXT_IIC2INTC_IRPT_INTR
#define XPAR_FABRIC_IIC_3_VEC_ID XPAR_FABRIC_AXI_IIC_MAIN_IIC2INTC_IRPT_INTR
#define XPAR_FABRIC_AXIVDMA_0_VEC_ID XPAR_FABRIC_AXI_HDMI_DMA_MM2S_INTROUT_INTR

/******************************************************************/

/* Definitions for driver SCUGIC */
#define XPAR_XSCUGIC_NUM_INSTANCES 1U

/* Definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_PS7_SCUGIC_0_DEVICE_ID 0U
#define XPAR_PS7_SCUGIC_0_BASEADDR 0xF8F00100U
#define XPAR_PS7_SCUGIC_0_HIGHADDR 0xF8F001FFU
#define XPAR_PS7_SCUGIC_0_DIST_BASEADDR 0xF8F01000U


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_SCUGIC_0_DEVICE_ID 0U
#define XPAR_SCUGIC_0_CPU_BASEADDR 0xF8F00100U
#define XPAR_SCUGIC_0_CPU_HIGHADDR 0xF8F001FFU
#define XPAR_SCUGIC_0_DIST_BASEADDR 0xF8F01000U


/******************************************************************/

/* Definitions for driver SCUTIMER */
#define XPAR_XSCUTIMER_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_PS7_SCUTIMER_0_DEVICE_ID 0
#define XPAR_PS7_SCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_PS7_SCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_XSCUTIMER_0_DEVICE_ID XPAR_PS7_SCUTIMER_0_DEVICE_ID
#define XPAR_XSCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_XSCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Definitions for driver SCUWDT */
#define XPAR_XSCUWDT_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_PS7_SCUWDT_0_DEVICE_ID 0
#define XPAR_PS7_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_PS7_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_SCUWDT_0_DEVICE_ID XPAR_PS7_SCUWDT_0_DEVICE_ID
#define XPAR_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Definitions for driver SDPS */
#define XPAR_XSDPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SD_0 */
#define XPAR_PS7_SD_0_DEVICE_ID 0
#define XPAR_PS7_SD_0_BASEADDR 0xE0100000
#define XPAR_PS7_SD_0_HIGHADDR 0xE0100FFF
#define XPAR_PS7_SD_0_SDIO_CLK_FREQ_HZ 50000000
#define XPAR_PS7_SD_0_HAS_CD 1
#define XPAR_PS7_SD_0_HAS_WP 1
#define XPAR_PS7_SD_0_BUS_WIDTH 0
#define XPAR_PS7_SD_0_MIO_BANK 0
#define XPAR_PS7_SD_0_HAS_EMIO 0


/******************************************************************/

#define XPAR_PS7_SD_0_IS_CACHE_COHERENT 0
/* Canonical definitions for peripheral PS7_SD_0 */
#define XPAR_XSDPS_0_DEVICE_ID XPAR_PS7_SD_0_DEVICE_ID
#define XPAR_XSDPS_0_BASEADDR 0xE0100000
#define XPAR_XSDPS_0_HIGHADDR 0xE0100FFF
#define XPAR_XSDPS_0_SDIO_CLK_FREQ_HZ 50000000
#define XPAR_XSDPS_0_HAS_CD 1
#define XPAR_XSDPS_0_HAS_WP 1
#define XPAR_XSDPS_0_BUS_WIDTH 0
#define XPAR_XSDPS_0_MIO_BANK 0
#define XPAR_XSDPS_0_HAS_EMIO 0
#define XPAR_XSDPS_0_IS_CACHE_COHERENT 0


/******************************************************************/

/* Definitions for driver SPI */
#define XPAR_XSPI_NUM_INSTANCES 1U

/* Definitions for peripheral OLED_SPI */
#define XPAR_OLED_SPI_DEVICE_ID 0U
#define XPAR_OLED_SPI_BASEADDR 0x41230000U
#define XPAR_OLED_SPI_HIGHADDR 0x4123FFFFU
#define XPAR_OLED_SPI_FIFO_DEPTH 16U
#define XPAR_OLED_SPI_FIFO_EXIST 1U
#define XPAR_OLED_SPI_SPI_SLAVE_ONLY 0U
#define XPAR_OLED_SPI_NUM_SS_BITS 1U
#define XPAR_OLED_SPI_NUM_TRANSFER_BITS 8U
#define XPAR_OLED_SPI_SPI_MODE 0U
#define XPAR_OLED_SPI_TYPE_OF_AXI4_INTERFACE 0U
#define XPAR_OLED_SPI_AXI4_BASEADDR 0U
#define XPAR_OLED_SPI_AXI4_HIGHADDR 0U
#define XPAR_OLED_SPI_XIP_MODE 0U

/* Canonical definitions for peripheral OLED_SPI */
#define XPAR_SPI_0_DEVICE_ID 0U
#define XPAR_SPI_0_BASEADDR 0x41230000U
#define XPAR_SPI_0_HIGHADDR 0x4123FFFFU
#define XPAR_SPI_0_FIFO_DEPTH 16U
#define XPAR_SPI_0_FIFO_EXIST 1U
#define XPAR_SPI_0_SPI_SLAVE_ONLY 0U
#define XPAR_SPI_0_NUM_SS_BITS 1U
#define XPAR_SPI_0_NUM_TRANSFER_BITS 8U
#define XPAR_SPI_0_SPI_MODE 0U
#define XPAR_SPI_0_TYPE_OF_AXI4_INTERFACE 0U
#define XPAR_SPI_0_AXI4_BASEADDR 0U
#define XPAR_SPI_0_AXI4_HIGHADDR 0U
#define XPAR_SPI_0_XIP_MODE 0U
#define XPAR_SPI_0_USE_STARTUP 0U



/******************************************************************/

/* Definitions for driver SPIPS */
#define XPAR_XSPIPS_NUM_INSTANCES 2

/* Definitions for peripheral PS7_SPI_0 */
#define XPAR_PS7_SPI_0_DEVICE_ID 0
#define XPAR_PS7_SPI_0_BASEADDR 0xE0006000
#define XPAR_PS7_SPI_0_HIGHADDR 0xE0006FFF
#define XPAR_PS7_SPI_0_SPI_CLK_FREQ_HZ 166666672


/* Definitions for peripheral PS7_SPI_1 */
#define XPAR_PS7_SPI_1_DEVICE_ID 1
#define XPAR_PS7_SPI_1_BASEADDR 0xE0007000
#define XPAR_PS7_SPI_1_HIGHADDR 0xE0007FFF
#define XPAR_PS7_SPI_1_SPI_CLK_FREQ_HZ 166666672


/******************************************************************/

/* Canonical definitions for peripheral PS7_SPI_0 */
#define XPAR_XSPIPS_0_DEVICE_ID XPAR_PS7_SPI_0_DEVICE_ID
#define XPAR_XSPIPS_0_BASEADDR 0xE0006000
#define XPAR_XSPIPS_0_HIGHADDR 0xE0006FFF
#define XPAR_XSPIPS_0_SPI_CLK_FREQ_HZ 166666672

/* Canonical definitions for peripheral PS7_SPI_1 */
#define XPAR_XSPIPS_1_DEVICE_ID XPAR_PS7_SPI_1_DEVICE_ID
#define XPAR_XSPIPS_1_BASEADDR 0xE0007000
#define XPAR_XSPIPS_1_HIGHADDR 0xE0007FFF
#define XPAR_XSPIPS_1_SPI_CLK_FREQ_HZ 166666672


/******************************************************************/

/* Definitions for driver SYSMON */
#define XPAR_XSYSMON_NUM_INSTANCES 1U

/* Definitions for peripheral XADC0 */
#define XPAR_XADC0_IP_TYPE 0U
#define XPAR_XADC0_DEVICE_ID 0U
#define XPAR_XADC0_BASEADDR 0x41650000U
#define XPAR_XADC0_HIGHADDR 0x4165FFFFU
#define XPAR_XADC0_INCLUDE_INTR 1U


/******************************************************************/

/* Canonical definitions for peripheral XADC0 */
#define XPAR_SYSMON_0_IP_TYPE 0U
#define XPAR_SYSMON_0_DEVICE_ID XPAR_XADC0_DEVICE_ID
#define XPAR_SYSMON_0_BASEADDR 0x41650000U
#define XPAR_SYSMON_0_HIGHADDR 0x4165FFFFU
#define XPAR_SYSMON_0_INCLUDE_INTR 1U


/******************************************************************/

/* Definitions for driver TMRCTR */
#define XPAR_XTMRCTR_NUM_INSTANCES 4U

/* Definitions for peripheral TMR0 */
#define XPAR_TMR0_DEVICE_ID 0U
#define XPAR_TMR0_BASEADDR 0x41240000U
#define XPAR_TMR0_HIGHADDR 0x41240FFFU
#define XPAR_TMR0_CLOCK_FREQ_HZ 100000000U


/* Definitions for peripheral TMR1 */
#define XPAR_TMR1_DEVICE_ID 1U
#define XPAR_TMR1_BASEADDR 0x41250000U
#define XPAR_TMR1_HIGHADDR 0x41250FFFU
#define XPAR_TMR1_CLOCK_FREQ_HZ 100000000U


/* Definitions for peripheral TMR2 */
#define XPAR_TMR2_DEVICE_ID 2U
#define XPAR_TMR2_BASEADDR 0x41280000U
#define XPAR_TMR2_HIGHADDR 0x41280FFFU
#define XPAR_TMR2_CLOCK_FREQ_HZ 100000000U


/* Definitions for peripheral TMR3 */
#define XPAR_TMR3_DEVICE_ID 3U
#define XPAR_TMR3_BASEADDR 0x41290000U
#define XPAR_TMR3_HIGHADDR 0x41290FFFU
#define XPAR_TMR3_CLOCK_FREQ_HZ 100000000U


/******************************************************************/

/* Canonical definitions for peripheral TMR0 */
#define XPAR_TMRCTR_0_DEVICE_ID 0U
#define XPAR_TMRCTR_0_BASEADDR 0x41240000U
#define XPAR_TMRCTR_0_HIGHADDR 0x41240FFFU
#define XPAR_TMRCTR_0_CLOCK_FREQ_HZ XPAR_TMR0_CLOCK_FREQ_HZ
/* Canonical definitions for peripheral TMR1 */
#define XPAR_TMRCTR_1_DEVICE_ID 1U
#define XPAR_TMRCTR_1_BASEADDR 0x41250000U
#define XPAR_TMRCTR_1_HIGHADDR 0x41250FFFU
#define XPAR_TMRCTR_1_CLOCK_FREQ_HZ XPAR_TMR1_CLOCK_FREQ_HZ
/* Canonical definitions for peripheral TMR2 */
#define XPAR_TMRCTR_2_DEVICE_ID 2U
#define XPAR_TMRCTR_2_BASEADDR 0x41280000U
#define XPAR_TMRCTR_2_HIGHADDR 0x41280FFFU
#define XPAR_TMRCTR_2_CLOCK_FREQ_HZ XPAR_TMR2_CLOCK_FREQ_HZ
/* Canonical definitions for peripheral TMR3 */
#define XPAR_TMRCTR_3_DEVICE_ID 3U
#define XPAR_TMRCTR_3_BASEADDR 0x41290000U
#define XPAR_TMRCTR_3_HIGHADDR 0x41290FFFU
#define XPAR_TMRCTR_3_CLOCK_FREQ_HZ XPAR_TMR3_CLOCK_FREQ_HZ

/******************************************************************/

/* Definitions for driver UARTLITE */
#define XPAR_XUARTLITE_NUM_INSTANCES 1

/* Definitions for peripheral UART0 */
#define XPAR_UART0_BASEADDR 0x412A0000
#define XPAR_UART0_HIGHADDR 0x412A0FFF
#define XPAR_UART0_DEVICE_ID 0
#define XPAR_UART0_BAUDRATE 115200
#define XPAR_UART0_USE_PARITY 0
#define XPAR_UART0_ODD_PARITY 0
#define XPAR_UART0_DATA_BITS 8


/******************************************************************/

/* Canonical definitions for peripheral UART0 */
#define XPAR_UARTLITE_0_DEVICE_ID XPAR_UART0_DEVICE_ID
#define XPAR_UARTLITE_0_BASEADDR 0x412A0000
#define XPAR_UARTLITE_0_HIGHADDR 0x412A0FFF
#define XPAR_UARTLITE_0_BAUDRATE 115200
#define XPAR_UARTLITE_0_USE_PARITY 0
#define XPAR_UARTLITE_0_ODD_PARITY 0
#define XPAR_UARTLITE_0_DATA_BITS 8


/******************************************************************/

/* Definitions for driver UARTPS */
#define XPAR_XUARTPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_UART_1 */
#define XPAR_PS7_UART_1_DEVICE_ID 0
#define XPAR_PS7_UART_1_BASEADDR 0xE0001000
#define XPAR_PS7_UART_1_HIGHADDR 0xE0001FFF
#define XPAR_PS7_UART_1_UART_CLK_FREQ_HZ 50000000
#define XPAR_PS7_UART_1_HAS_MODEM 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_UART_1 */
#define XPAR_XUARTPS_0_DEVICE_ID XPAR_PS7_UART_1_DEVICE_ID
#define XPAR_XUARTPS_0_BASEADDR 0xE0001000
#define XPAR_XUARTPS_0_HIGHADDR 0xE0001FFF
#define XPAR_XUARTPS_0_UART_CLK_FREQ_HZ 50000000
#define XPAR_XUARTPS_0_HAS_MODEM 0


/******************************************************************/

/* Definitions for driver USBPS */
#define XPAR_XUSBPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_USB_0 */
#define XPAR_PS7_USB_0_DEVICE_ID 0
#define XPAR_PS7_USB_0_BASEADDR 0xE0002000
#define XPAR_PS7_USB_0_HIGHADDR 0xE0002FFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_USB_0 */
#define XPAR_XUSBPS_0_DEVICE_ID XPAR_PS7_USB_0_DEVICE_ID
#define XPAR_XUSBPS_0_BASEADDR 0xE0002000
#define XPAR_XUSBPS_0_HIGHADDR 0xE0002FFF


/******************************************************************/

/* Definitions for driver XADCPS */
#define XPAR_XADCPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_XADC_0 */
#define XPAR_PS7_XADC_0_DEVICE_ID 0
#define XPAR_PS7_XADC_0_BASEADDR 0xF8007100
#define XPAR_PS7_XADC_0_HIGHADDR 0xF8007120


/******************************************************************/

/* Canonical definitions for peripheral PS7_XADC_0 */
#define XPAR_XADCPS_0_DEVICE_ID XPAR_PS7_XADC_0_DEVICE_ID
#define XPAR_XADCPS_0_BASEADDR 0xF8007100
#define XPAR_XADCPS_0_HIGHADDR 0xF8007120


/******************************************************************/

#endif  /* end of protection macro */
