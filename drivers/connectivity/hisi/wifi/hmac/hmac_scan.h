

#ifndef __HMAC_SCAN_H__
#define __HMAC_SCAN_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "oal_ext_if.h"
#include "frw_ext_if.h"
#include "hmac_vap.h"
#include "mac_device.h"
#include "hmac_device.h"



#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_HMAC_SCAN_H
/*****************************************************************************
  2 宏定义
*****************************************************************************/

/* 扫描到的bss的老化时间，小于此值，下发新扫描请求时，不删除此bss信息 */
#define HMAC_SCAN_MAX_SCANNED_BSS_EXPIRE         25000   /* 25000 milliseconds */

/* 扫描结果中有效性高的时间范围，可用于漫游目标的挑选等操作 */
#define HMAC_SCAN_MAX_VALID_SCANNED_BSS_EXPIRE   3000    /* 3000 milliseconds */

/* 扫描到的bss的rssi老化时间 */
#define HMAC_SCAN_MAX_SCANNED_RSSI_EXPIRE        1000    /* 1000 milliseconds */

#define HMAC_INIT_SCAN_TIMEOUT_MS   10000
/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/

/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
/* HMAC SCAN对外接口 */
extern oal_void hmac_scan_print_scanned_bss_info(oal_uint8 uc_device_id);

extern mac_bss_dscr_stru *hmac_scan_find_scanned_bss_dscr_by_index(oal_uint8  uc_device_id,
                                                                                oal_uint32 ul_bss_index);
extern hmac_scanned_bss_info *hmac_scan_find_scanned_bss_by_bssid(hmac_bss_mgmt_stru *pst_bss_mgmt, oal_uint8 *puc_bssid);
extern oal_uint32 hmac_scan_proc_scanned_bss(frw_event_mem_stru *pst_event_mem);
extern oal_uint32  hmac_scan_proc_scan_comp_event(frw_event_mem_stru *pst_event_mem);
extern oal_uint32  hmac_scan_proc_scan_req_event_exception(hmac_vap_stru *pst_hmac_vap, oal_void *p_params);
extern oal_uint32  hmac_scan_proc_scan_req_event(hmac_vap_stru *pst_hmac_vap, oal_void *p_params);
extern oal_uint32  hmac_scan_proc_sched_scan_req_event(hmac_vap_stru *pst_hmac_vap, oal_void *p_params);
extern oal_void    hmac_scan_init(hmac_device_stru *pst_hmac_device);
extern oal_void    hmac_scan_exit(hmac_device_stru *pst_hmac_device);
extern oal_uint32  hmac_scan_process_chan_result_event(frw_event_mem_stru *pst_event_mem);
#ifdef _PRE_DEBUG_MODE
extern oal_uint32  hmac_scan_test(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param);
#endif
extern oal_uint32  hmac_bgscan_enable(mac_vap_stru *pst_mac_vap, oal_uint16 us_len, oal_uint8 *puc_param);
#if defined(_PRE_SUPPORT_ACS) || defined(_PRE_WLAN_FEATURE_DFS) || defined(_PRE_WLAN_FEATURE_20_40_80_COEXIST)
extern oal_uint32 hmac_init_scan_process(hmac_device_stru *pst_mac_dev, mac_vap_stru *pst_mac_vap, mac_scan_op_enum_uint8 en_op_type);
extern oal_uint32 hmac_init_scan_try(mac_device_stru *pst_mac_device, mac_vap_stru *pst_mac_vap, mac_try_init_scan_type en_type);
extern oal_uint32 hmac_init_scan_cancel_timer(hmac_device_stru *pst_hmac_dev);
extern oal_bool_enum_uint8 hmac_device_in_init_scan(mac_device_stru *pst_mac_device);
#endif
extern oal_uint32 hmac_start_all_bss_of_device(hmac_device_stru *pst_dev);
extern oal_void  hmac_scan_set_sour_mac_addr_in_probe_req(hmac_vap_stru        *pst_hmac_vap,
                                                              oal_uint8            *puc_sour_mac_addr,
                                                              oal_bool_enum_uint8   en_is_rand_mac_addr_scan,
                                                              oal_bool_enum_uint8   en_is_p2p0_scan);
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of hmac_scan.h */
