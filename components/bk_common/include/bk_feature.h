// Copyright 2020-2022 Beken
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* @brief Overview about this API header
 *
 */

/**
 * @brief     Interface for customer to Enable/Disable bssid connect functionality
 *
 * @attention 1 Controled by middleware/soc/bk72xx.defconfig
 * @attention 2 Support to use with fast connect
 *
 * @return
 *    - 1: enable
 *    - 0: disable
 */
int bk_feature_bssid_connect_enable(void);

/**
 * @brief     Interface for customer to Enable/Disable fast connect functionality
 *
 * @attention 1 This API only enable phase 1 fast connect (skip psk calculate、all channel scanning)
 * @attention 2 Controled by middleware/soc/bk72xx.defconfig
 *
 * @return
 *    - 1: enable
 *    - 0: disable
 */
int bk_feature_fast_connect_enable(void);

/**
 * @brief     Interface for customer to Enable/Disable fast dhcp functionality
 *
 * @attention 1 This API only enable phase 2 fast connect (skip dhcp and use static ip saved in flash)
 * @attention 2 Controled by middleware/soc/bk72xx.defconfig
 *
 * @return
 *    - 1: enable
 *    - 0: disable
 */
int bk_feature_fast_dhcp_enable(void);

/**
 * @brief     Interface for customer to Enable/Disable Station Vendor Specific IEs
 *
 * @attention 1 Controled by middleware/soc/bk72xx.defconfig
 *
 * @return
 *    - 1: enable
 *    - 0: disable
 */
int bk_feature_sta_vsie_enable(void);

/**
 * @brief     Interface for customer to Enable/Disable max limit connection of sta to softap
 *
 * @attention 1 Controled by middleware/soc/bk72xx.defconfig
 *
 * @return
 *    - 1: enable
 *    - 0: disable
 */
int bk_feature_ap_statype_limit_enable(void);

/**
 * @brief     Interface for customer to Enable/Disable temp detect functionality
 *
 * @attention 1 Controled by middleware/soc/bk72xx.defconfig
 *
 * @return
 *    - 1: enable
 *    - 0: disable
 */
int bk_feature_temp_detect_enable(void);

/**
 * @brief     Interface for customer to Enable/Disable lvgl use psram functionality
 *
 * @attention 1 Controled by middleware/soc/bk72xx.defconfig
 *
 * @return
 *    - 1: enable
 *    - 0: disable
 */
int bk_feature_lvgl_use_psram_enable(void);

/**
 * @brief     Interface for customer to Enable/Disable lvgl use direct mode functionality
 *
 * @attention 1 Controled by middleware/soc/bk72xx.defconfig
 * @attention 2 The macro only takes effect if the LVGL use psram
 *
 * @return
 *    - 1: enable
 *    - 0: disable
 */
int bk_feature_lvgl_use_direct_mode_enable(void);


typedef enum {
    BK_CPU0 = 0, /**< cpu0 id */
    BK_CPU1 = 1, /**< cpu1 id */
    BK_CPU2 = 2 /**< cpu2 id */
} BK_CPU_ID;


/**
 * @brief     Interface to get if current system is cpu0
 *
 *
 * @return
 *    - BK_CPU0: current system is cpu0
 *    - BK_CPU1: current system is cpu1
 *    - BK_CPU2: current system is cpu2
 *
 */
int bk_feature_get_cpu_id(void);


/**
 * @brief     Interface to get the cpu count of system
 *
 *
 * @return
 *    - 1: current system is single core
 *    - 2: current system is dual core
 *    - 3: current system is triple core
 *
 */
int bk_feature_get_cpu_cnt(void);

