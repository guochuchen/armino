/*
 * Automatically generated file. DO NOT EDIT.
 * Beken IoT Development Framework (BEKEN-ARMINO) Configuration Header
 */
#pragma once
#define CONFIG_SOC_BK7235 1
#define CONFIG_SOC_STR "bk7235"
#define CONFIG_SOC_ARCH "riscv"
#define CONFIG_SOC_BK7256XX 1
#define CONFIG_TOOLCHAIN_PATH "/opt/risc-v/nds32le-elf-mculib-v5/bin"
#define CONFIG_TOOLCHAIN_PREFIX "riscv32-elf-"
#define CONFIG_ASSERT_REBOOT 1
#define CONFIG_LWIP 1
#define CONFIG_LWIP_V2_1 1
#define CONFIG_NO_HOSTED 1
#define CONFIG_BLUETOOTH 1
#define CONFIG_BK_AIRKISS 1
#define CONFIG_CALI 1
#define CONFIG_MANUAL_CALI 1
#define CONFIG_TPC_PA_MAP 1
#define CONFIG_TEMP_DETECT 1
#define CONFIG_LA_CAPTURE_MAC_DIAGS 1
#define CONFIG_RF_POLICY_SUPPORT 1
#define CONFIG_RF_POLICY_BLE_REQ 1
#define CONFIG_BK_HOSTAPD 1
#define CONFIG_DEVICE_MAX_NAME_LEN 32
#define CONFIG_INT_WDT 1
#define CONFIG_INT_WDT_PERIOD_MS 1000
#define CONFIG_TASK_WDT 1
#define CONFIG_TASK_WDT_PERIOD_MS 60000
#define CONFIG_NMI_WDT_EN 1
#define CONFIG_INT_AON_WDT_PERIOD_MS 1000
#define CONFIG_UART1 1
#define CONFIG_UART2 1
#define CONFIG_UART_PRINT_PORT 0
#define CONFIG_UART_ATE_PORT 0
#define CONFIG_PRINTF_BUF_SIZE 128
#define CONFIG_KFIFO_SIZE 128
#define CONFIG_UART_LOW_VOLTAGE_SUPPORT 1
#define CONFIG_TRNG_SUPPORT 1
#define CONFIG_SDIO_HOST_DEFAULT_CLOCK_FREQ 200000
#define CONFIG_SDCARD_DEFAULT_CLOCK_FREQ 9
#define CONFIG_SPI_DMA 1
#define CONFIG_SPI_SLAVE 1
#define CONFIG_SPI_MASTER 1
#define CONFIG_SPI_STATIS 1
#define CONFIG_SPI_SUPPORT_TX_FIFO_WR_READY 1
#define CONFIG_QSPI_STATIS 1
#define CONFIG_AON_RTC 1
#define CONFIG_AON_RTC_MANY_USERS 1
#define CONFIG_AON_RTC_TEST 1
#define CONFIG_AON_RTC_KEEP_TIME_SUPPORT 1
#define CONFIG_GPIO_WAKEUP_SUPPORT 1
#define CONFIG_GPIO_DYNAMIC_WAKEUP_SUPPORT 1
#define CONFIG_GPIO_DYNAMIC_WAKEUP_SOURCE_MAX_CNT 4
#define CONFIG_CONFIG_GPIO_WAKEUP_ID 22
#define CONFIG_CONFIG_GPIO_WAKEUP_INT_TYPE 0
#define CONFIG_GPIO_SIMULATE_UART_WRITE 1
#define CONFIG_GPIO_DEFAULT_SET_SUPPORT 1
#define CONFIG_AON_PMU 1
#define CONFIG_GENERAL_DMA 1
#define CONFIG_XTAL_FREQ_26M 1
#define CONFIG_XTAL_FREQ 26000000
#define CONFIG_DCO_FREQ 120000000
#define CONFIG_SYSTEM_CTRL 1
#define CONFIG_POWER_CLOCK_RF 1
#define CONFIG_DEFAULT_LPO_SRC 2
#define CONFIG_MAC_PHY_BYPASS 1
#define CONFIG_I2C 1
#define CONFIG_I2C_SUPPORT_ID_BITS 1
#define CONFIG_SIM_I2C 1
#define CONFIG_PWM 1
#define CONFIG_TIMER 1
#define CONFIG_TIMER_COUNTER 1
#define CONFIG_TIMER_SUPPORT_ID_BITS 63
#define CONFIG_SARADC 1
#define CONFIG_SARADC_RANGE_DIVIDE 1
#define CONFIG_FLASH 1
#define CONFIG_FLASH_QUAD_ENABLE 1
#define CONFIG_FLASH_SRC_CLK_60M 1
#define CONFIG_RESET_REASON 1
#define CONFIG_EFUSE 1
#define CONFIG_CHIP_SUPPORT 1
#define CONFIG_CPU_FREQ_HZ 120000000
#define CONFIG_ARCH_RISCV 1
#define CONFIG_NEST_INT_SUPPORT 1
#define CONFIG_MEMDUMP_ALL 1
#define CONFIG_CACHE_ENABLE 1
#define CONFIG_BLE 1
#define CONFIG_BTDM_5_2 1
#define CONFIG_CLI 1
#define CONFIG_BKREG 1
#define CONFIG_MAX_COMMANDS 255
#define CONFIG_IPERF_TEST 1
#define CONFIG_I2C2_TEST 1
#define CONFIG_SPI_TEST 1
#define CONFIG_PERI_TEST 1
#define CONFIG_SHELL_ASYNCLOG 1
#define CONFIG_SECURITYIP 1
#define CONFIG_IDLE_UART_OUT_TEST 1
#define CONFIG_CUSTOMIZE_HEAP_SIZE 163840
#define CONFIG_FREERTOS 1
#define CONFIG_FREERTOS_V10 1
#define CONFIG_FREERTOS_USE_TICKLESS_IDLE 2
#define CONFIG_MEM_DEBUG 1
#define CONFIG_MEM_DEBUG_FUNC_NAME 1
#define CONFIG_MEM_DEBUG_FUNC_NAME_LEN 16
#define CONFIG_MEM_DEBUG_TASK_NAME 1
#define CONFIG_MEM_DEBUG_TASK_NAME_LEN 8
#define CONFIG_DHCP 1
#define CONFIG_MDNS 1
#define CONFIG_TASK_LWIP_PRIO 4
#define CONFIG_LWIP_MEM_REDUCE 1
#define CONFIG_MQTT_ACK_NOW 1
#define CONFIG_LWIP_MEM_TRX_DYNAMIC_EN 1
#define CONFIG_LWIP_MEMP_STATS 1
#define CONFIG_LWIP_MEM_STATS 1
#define CONFIG_WIFI_ENABLE 1
#define CONFIG_WIFI6_CODE_STACK 1
#define CONFIG_WIFI6 1
#define CONFIG_WIFI4 1
#define CONFIG_MSDU_RESV_HEAD_LENGTH 96
#define CONFIG_MSDU_RESV_TAIL_LENGTH 16
#define CONFIG_TASK_RECONNECT_PRIO 4
#define CONFIG_WIFI6_IP_DEBUG 1
#define CONFIG_STA_PS 1
#define CONFIG_MAC_BSSID 1
#define CONFIG_BLE_PS 1
#define CONFIG_BLE_HOST_RW 1
#define CONFIG_BLE_MESH_NONE 1
#define CONFIG_BLE_ADV_NUM 1
#define CONFIG_BLE_SCAN_NUM 1
#define CONFIG_BLE_INIT_NUM 1
#define CONFIG_BLE_CONN_NUM 3
#define CONFIG_BLE_WIFI_EXCHANGE 1
#define CONFIG_ACLSEMI_BTC_FEATURE_INCLUDED 1
#define CONFIG_BT_CONN_NUM 7
#define CONFIG_ACLSEMI_BT_MESH_DEBUG_LEVEL 4
#define CONFIG_SELF_LE_INIT_UPDATE_CON_PARAM 1
#define CONFIG_SELF_LE_INIT_SDP 1
#define CONFIG_HOMEKIT 1
#define CONFIG_WIFI_IP_AX 1
#define CONFIG_WIFI_MAC_VERSION "V21"
#define CONFIG_WIFI_MDM_VERSION "v30"
#define CONFIG_WIFI_PLF_VERSION "v31"
#define CONFIG_MOBILE_CONNECT_SAP_STATISTICS 1
#define CONFIG_MM_PS_SET_LISTEN_INTERVAL_VALUE 30
#define CONFIG_MM_BEACON_LOSS_INITAL_COEFF 4
#define CONFIG_MM_BEACON_LOSS_LOW_COEFF 8
#define CONFIG_MM_BEACON_LOSS_MIDDLE_COEFF 20
#define CONFIG_MM_BEACON_LOSS_HIGH_COEFF 40
#define CONFIG_MM_BEACON_LOSS_RSSI_THRESHOLD -80
#define CONFIG_HE_MCS_LIMIT_7 1
#define CONFIG_MAC_CHAN 1
#define CONFIG_SPECIAL_TX_TYPE 1
#define CONFIG_MAC_RESET_BCMC_AUTO_MODE 1
#define CONFIG_MAC_KEEP_ALIVE_PERIOD_AUTO_MODE 1
#define CONFIG_DHCP_PROTECT_IN_CONNECTED 1
#define CONFIG_TCP_PROTECT_IN_CONNECTED 1
#define CONFIG_BK_MEMORY_CUT_EN 1
#define CONFIG_NX_HW_PARSER_TIM_ELEMENT 1
#define CONFIG_MAC_SUPPORT_DYNAMIC_CPU_FREQ 1
#define CONFIG_MAC_PM_ROSC_CALI 1
#define CONFIG_NX_MEDIA_DYNC_DTIM 1
#define CONFIG_PER_PACKET_INFO_OUTPUT 1
#define CONFIG_BK_MEM_DYNA_APPLY_EN 1
#define CONFIG_NX_OTA_DYNC_DTIM 1
#define CONFIG_MAC_SFRAME_SOFTWARE_RETRY 1
#define CONFIG_SM_FAST_CONNECT 1
#define CONFIG_NET_PARAM_INTF 1
#define CONFIG_POWER_SAVE 1
#define CONFIG_MCU_PS 1
#define CONFIG_TICK_CALI 1
#define CONFIG_PM_V2 1
#define CONFIG_MAC_TX_CACHE 1
#define CONFIG_RF_TEST 1
#define CONFIG_TX_EVM_TEST 1
#define CONFIG_RX_SENSE_TEST 1
#define CONFIG_WIFI_RWNX 1
#define CONFIG_WIFI_KMSG_TASK_PRIO 3
#define CONFIG_WIFI_KMSG_TASK_STACK_SIZE 4096
#define CONFIG_WIFI_CORE_TASK_PRIO 2
#define CONFIG_WIFI_CORE_TASK_STACK_SIZE 2048
#define CONFIG_RWNX_QOS_MSDU 1
#define CONFIG_MSDU_RESV_HEAD_LEN 96
#define CONFIG_MSDU_RESV_TAIL_LEN 16
#define CONFIG_WPA_TWT_TEST 1
#define CONFIG_ATE 1
#define CONFIG_DSP_SRC_ADD 0x130000
#define CONFIG_VAD 1
#define CONFIG_WOLFSSL_BEKEN 1
#define CONFIG_TASK_WPAS_PRIO 5
#define CONFIG_WPA3 1
#define CONFIG_PMF 1
#define CONFIG_AP_HT_IE 1
#define CONFIG_AP_VHT 1
#define CONFIG_AP_HE 1
#define CONFIG_AP_VSIE 1
#define CONFIG_WPA_PSK_CACHE 1
#define CONFIG_FAST_CONNECT_INFO_ENC_METHOD 1
#define CONFIG_WPA_AUTH_TIMEOUT 2
#define CONFIG_WPA_SUPPLICANT_2_9 1
#define CONFIG_WPA_CTRL_IFACE 1
