

#ifndef __MAC_REGDOMAIN_H__
#define __MAC_REGDOMAIN_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "oal_ext_if.h"
#include "wlan_spec.h"
#include "wlan_types.h"

#undef  THIS_FILE_ID
#define THIS_FILE_ID OAM_FILE_ID_MAC_REGDOMAIN_H
/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define MAC_GET_CH_BIT(_val) (1 << (_val))

/* Ĭ�Ϲ���������͹��� */
#if (_PRE_MULTI_CORE_MODE_OFFLOAD_DMAC != _PRE_MULTI_CORE_MODE)
#define MAC_RC_DEFAULT_MAX_TX_PWR   20      /* 20dBm */
#else
#define MAC_RC_DEFAULT_MAX_TX_PWR   30
#endif

#define MAC_RD_BMAP_SIZE            32

#define MAC_COUNTRY_SIZE            2       /* ��������2���ַ� */

#define MAC_INVALID_RC              255     /* ��Ч�Ĺ���������ֵ */

#define MAC_SEC_CHAN_INDEX_OFFSET_START_FREQ_5       1
#define MAC_AFFECTED_CHAN_OFFSET_START_FREQ_5        0
#define MAC_SEC_CHAN_INDEX_OFFSET_START_FREQ_2       4
#define MAC_AFFECTED_CHAN_OFFSET_START_FREQ_2        3

#define MAX_CHANNEL_NUM_FREQ_2G                      14     /* 2GƵ�������ŵ��� */

#define MAC_MAX_20M_SUB_CH    8      /* VHT160�У�20MHz�ŵ��ܸ��� */

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/* һ�����������ʼƵ��ö�� */
typedef enum
{
    MAC_RC_START_FREQ_2  = WLAN_BAND_2G,  /* 2.407 */
    MAC_RC_START_FREQ_5  = WLAN_BAND_5G,  /* 5 */


    MAC_RC_START_FREQ_BUTT,
}mac_rc_start_freq_enum;
typedef oal_uint8 mac_rc_start_freq_enum_uint8;

/* �������ŵ���� */
typedef enum
{
    MAC_CH_SPACING_5MHZ = 0,
    MAC_CH_SPACING_10MHZ,
    MAC_CH_SPACING_20MHZ,
    MAC_CH_SPACING_25MHZ,
    MAC_CH_SPACING_40MHZ,
    MAC_CH_SPACING_80MHZ,

    MAC_CH_SPACING_BUTT
}mac_ch_spacing_enum;
typedef oal_uint8 mac_ch_spacing_enum_uint8;

/* �״���֤��׼ö�� */
typedef enum
{
    MAC_DFS_DOMAIN_NULL  = 0,
    MAC_DFS_DOMAIN_FCC   = 1,
    MAC_DFS_DOMAIN_ETSI  = 2,
    MAC_DFS_DOMAIN_MKK   = 3,
    MAC_DFS_DOMAIN_KOREA = 4,

    MAC_DFS_DOMAIN_BUTT
}mac_dfs_domain_enum;
typedef oal_uint8 mac_dfs_domain_enum_uint8;

/* 5GHzƵ��: �ŵ��Ŷ�Ӧ���ŵ�����ֵ */
typedef enum
{
    MAC_CHANNEL36  = 0,
    MAC_CHANNEL40  = 1,
    MAC_CHANNEL44  = 2,
    MAC_CHANNEL48  = 3,
    MAC_CHANNEL52  = 4,
    MAC_CHANNEL56  = 5,
    MAC_CHANNEL60  = 6,
    MAC_CHANNEL64  = 7,
    MAC_CHANNEL100 = 8,
    MAC_CHANNEL104 = 9,
    MAC_CHANNEL108 = 10,
    MAC_CHANNEL112 = 11,
    MAC_CHANNEL116 = 12,
    MAC_CHANNEL120 = 13,
    MAC_CHANNEL124 = 14,
    MAC_CHANNEL128 = 15,
    MAC_CHANNEL132 = 16,
    MAC_CHANNEL136 = 17,
    MAC_CHANNEL140 = 18,
    MAC_CHANNEL144 = 19,
    MAC_CHANNEL149 = 20,
    MAC_CHANNEL153 = 21,
    MAC_CHANNEL157 = 22,
    MAC_CHANNEL161 = 23,
    MAC_CHANNEL165 = 24,
    MAC_CHANNEL184 = 25,
    MAC_CHANNEL188 = 26,
    MAC_CHANNEL192 = 27,
    MAC_CHANNEL196 = 28,
    MAC_CHANNEL_FREQ_5_BUTT = 29,
}mac_channel_freq_5_enum;
typedef oal_uint8 mac_channel_freq_5_enum_uint8;

/* 2.4GHzƵ��: �ŵ��Ŷ�Ӧ���ŵ�����ֵ */
typedef enum
{
    MAC_CHANNEL1  = 0,
    MAC_CHANNEL2  = 1,
    MAC_CHANNEL3  = 2,
    MAC_CHANNEL4  = 3,
    MAC_CHANNEL5  = 4,
    MAC_CHANNEL6  = 5,
    MAC_CHANNEL7  = 6,
    MAC_CHANNEL8  = 7,
    MAC_CHANNEL9  = 8,
    MAC_CHANNEL10 = 9,
    MAC_CHANNEL11 = 10,
    MAC_CHANNEL12 = 11,
    MAC_CHANNEL13 = 12,
    MAC_CHANNEL14 = 13,
    MAC_CHANNEL_FREQ_2_BUTT = 14,
}mac_channel_freq_2_enum;
typedef oal_uint8 mac_channel_freq_2_enum_uint8;

// note:change alg/acs/acs_cmd_resp.h as while
typedef enum
{
    MAC_RC_DFS               = BIT0,
    MAC_RC_NO_OUTDOOR        = BIT1,
    MAC_RC_NO_INDOOR         = BIT2,
}mac_behaviour_bmap_enum;

typedef oal_bool_enum (*p_mac_regdomain_channel_is_support_bw_cb)(wlan_channel_bandwidth_enum_uint8 en_cfg_bw, oal_uint8 uc_channel);
typedef struct
{
    p_mac_regdomain_channel_is_support_bw_cb                p_mac_regdomain_channel_is_support_bw;
}mac_regdomain_rom_cb;
extern mac_regdomain_rom_cb g_st_mac_regdomain_rom_cb;


#define MAC_MAX_SUPP_CHANNEL    (oal_uint8)(OAL_MAX((oal_uint8)MAC_CHANNEL_FREQ_2_BUTT, (oal_uint8)MAC_CHANNEL_FREQ_5_BUTT))

/*****************************************************************************
  5 ��Ϣͷ
*****************************************************************************/

/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/
/* ������ṹ��: ÿ�������ౣ�����Ϣ */

/* ��������������ṹ�� */
typedef struct
{
    oal_void *p_mac_regdom;
}mac_cfg_country_stru;

typedef struct
{
    mac_rc_start_freq_enum_uint8    en_start_freq;          /* ��ʼƵ�� */
    mac_ch_spacing_enum_uint8       en_ch_spacing;          /* �ŵ���� */
    oal_uint8                       uc_behaviour_bmap;      /* ��������Ϊλͼ λͼ�����mac_behaviour_bmap_enum */
    oal_uint8                       uc_coverage_class;      /* ������ */
    oal_uint8                       uc_max_reg_tx_pwr;      /* ������涨������͹���, ��λdBm */
    oal_uint16                      us_max_tx_pwr;          /* ʵ��ʹ�õ�����͹���,������10�����ڼ���, ��λdBm�����Աȹ�����涨���ʴ� */
    oal_uint8                       auc_resv[1];
    oal_uint32                      ul_channel_bmap;        /* ֧���ŵ�λͼ���� 0011��ʾ֧�ֵ��ŵ���indexΪ0 1 */
}mac_regclass_info_stru;

/* ��������Ϣ�ṹ�� */
/* ������ֵ��������λͼ���������Ϣ �����±��Ĺ�ϵ
    ������ȡֵ        : .... 7  6  5  4  3  2  1  0
    ������λͼ        : .... 1  1  0  1  1  1  0  1
    ��������Ϣ�����±�: .... 5  4  x  3  2  1  x  0
*/
typedef struct
{
    oal_int8                            ac_country[WLAN_COUNTRY_STR_LEN];       /* �����ַ��� */
    mac_dfs_domain_enum_uint8           en_dfs_domain;                          /* DFS �״��׼ */
    oal_uint8                           uc_regclass_num;                        /* ��������� */
    oal_bool_enum_uint8                 en_fcc_country;
    oal_uint8                           auc_resv[2];
    mac_regclass_info_stru              ast_regclass[WLAN_MAX_RC_NUM];          /* ����������Ĺ�������Ϣ��ע�� �˳�Աֻ�ܷ������һ��! */
}mac_regdomain_info_stru;

#define MAC_RD_INFO_LEN                 12  /* mac_regdomain_info_struȥ��mac_regclass_info_stru�ĳ��� */

/* channel info�ṹ�� */
typedef struct
{
    oal_uint8       uc_chan_number;     /* �ŵ��� */
    oal_uint8       uc_reg_class;       /* �������ڹ������е������� */
    oal_uint8       auc_resv[2];
}mac_channel_info_stru;


typedef struct
{
    oal_uint16  us_freq;        /* ����Ƶ�ʣ���λMHz */
    oal_uint8   uc_number;      /* �ŵ��� */
    oal_uint8   uc_idx;         /* �ŵ�����(������) */
}mac_freq_channel_map_stru;


typedef struct
{
    oal_uint32                   ul_channels;
    mac_freq_channel_map_stru    ast_channels[MAC_MAX_20M_SUB_CH];
}mac_channel_list_stru;

typedef struct
{
    oal_uint8   uc_cnt;
    wlan_channel_bandwidth_enum_uint8   aen_supp_bw[WLAN_BW_CAP_BUTT];
}mac_supp_mode_table_stru;


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 ȫ�ֱ�������
*****************************************************************************/
extern mac_regdomain_info_stru g_st_mac_regdomain;

extern mac_channel_info_stru g_ast_channel_list_5G[];

extern mac_channel_info_stru g_ast_channel_list_2G[];

extern OAL_CONST mac_freq_channel_map_stru g_ast_freq_map_5g[];

extern OAL_CONST mac_freq_channel_map_stru g_ast_freq_map_2g[];

/*****************************************************************************
  10 ��������
*****************************************************************************/
extern oal_void  mac_get_regdomain_info(mac_regdomain_info_stru **ppst_rd_info);
extern oal_void  mac_init_regdomain(oal_void);
extern oal_void  mac_init_channel_list(oal_void);
extern oal_uint32  mac_get_channel_num_from_idx(
                oal_uint8                    uc_band,
                oal_uint8                    uc_idx,
                oal_uint8                   *puc_channel_num);
extern oal_uint32 mac_get_channel_idx_from_num(
                   oal_uint8                    uc_band,
                   oal_uint8                    uc_channel_num,
                   oal_uint8                   *puc_channel_idx);
extern oal_uint32 mac_is_channel_idx_valid(oal_uint8 uc_band, oal_uint8 uc_ch_idx);
extern oal_uint32  mac_is_channel_num_valid(oal_uint8 uc_band, oal_uint8 uc_ch_num);

#ifdef _PRE_WLAN_FEATURE_11D
extern oal_uint32  mac_set_country_ie_2g(
                mac_regdomain_info_stru *pst_rd_info,
                oal_uint8               *puc_buffer,
                oal_uint8               *puc_len);

extern oal_uint32  mac_set_country_ie_5g(
                mac_regdomain_info_stru *pst_rd_info,
                oal_uint8               *puc_buffer,
                oal_uint8               *puc_len);
#endif


extern oal_uint32  mac_regdomain_set_country(oal_uint16 us_len, oal_uint8 *puc_param);
extern oal_int8*  mac_regdomain_get_country(oal_void);
extern mac_regclass_info_stru* mac_get_channel_idx_rc_info(oal_uint8 uc_band, oal_uint8 uc_ch_idx);
extern mac_regclass_info_stru* mac_get_channel_num_rc_info(oal_uint8 uc_band, oal_uint8 uc_ch_num);
extern oal_uint32  mac_regdomain_set_max_power(oal_uint8 uc_pwr, oal_bool_enum_uint8 en_exceed_reg);
extern oal_void  mac_get_ext_chan_info(
                oal_uint8                            uc_pri20_channel_idx,
                wlan_channel_bandwidth_enum_uint8    en_bandwidth,
                mac_channel_list_stru                *pst_chan_info);
extern oal_bool_enum_uint8 mac_is_cover_dfs_channel(
                oal_uint8                           uc_band,
                wlan_channel_bandwidth_enum_uint8   en_bandwidth,
                oal_uint8                           uc_channel_num);
extern wlan_channel_bandwidth_enum_uint8  mac_regdomain_get_support_bw_mode(wlan_channel_bandwidth_enum_uint8 en_chan_width,
                                                                            oal_uint8 uc_channel);
oal_bool_enum mac_regdomain_channel_is_support_bw(wlan_channel_bandwidth_enum_uint8 en_cfg_bw, oal_uint8 uc_channel);



OAL_STATIC OAL_INLINE wlan_channel_band_enum_uint8 mac_get_band_by_channel_num(oal_uint8 uc_channel_num)
{
    return ((uc_channel_num > MAX_CHANNEL_NUM_FREQ_2G) ? WLAN_BAND_5G : WLAN_BAND_2G);/* [false alarm]:����ֵΪ����ֵ0����1����Ӱ��*/
}


OAL_STATIC OAL_INLINE oal_bool_enum_uint8 mac_is_ch_supp_in_regclass(mac_regclass_info_stru *pst_rc_info, oal_uint8 uc_freq, oal_uint8 uc_ch_idx)
{
/* E5��֧��144�ŵ� */
#if (_PRE_CONFIG_TARGET_PRODUCT == _PRE_TARGET_PRODUCT_TYPE_E5)
    if (19 == uc_ch_idx)
    {
        return OAL_FALSE;
    }
#endif

    if (OAL_PTR_NULL == pst_rc_info)
    {
        return OAL_FALSE;
    }

    if (pst_rc_info->en_start_freq != uc_freq)
    {
        return OAL_FALSE;
    }

    if((pst_rc_info->ul_channel_bmap & MAC_GET_CH_BIT(uc_ch_idx)) != 0)
    {
        return OAL_TRUE;
    }

    return OAL_FALSE;
}


OAL_STATIC OAL_INLINE oal_uint8  mac_get_num_supp_channel(wlan_channel_band_enum_uint8 en_band)
{
    switch (en_band)
    {
        case WLAN_BAND_2G:   /* 2.4GHz */
            return (oal_uint8)MAC_CHANNEL_FREQ_2_BUTT;

        case WLAN_BAND_5G:   /* 5GHz */
            return (oal_uint8)MAC_CHANNEL_FREQ_5_BUTT;

        default:
            return 0;
    }
}


OAL_STATIC OAL_INLINE oal_uint8  mac_get_sec_ch_idx_offset(wlan_channel_band_enum_uint8 en_band)
{
    switch (en_band)
    {
        case WLAN_BAND_2G:   /* 2.4GHz */
            return (oal_uint8)MAC_SEC_CHAN_INDEX_OFFSET_START_FREQ_2;

        case WLAN_BAND_5G:   /* 5GHz */
            return (oal_uint8)MAC_SEC_CHAN_INDEX_OFFSET_START_FREQ_5;

        default:
            return 0;
    }
}


OAL_STATIC OAL_INLINE oal_uint8  mac_get_affected_ch_idx_offset(wlan_channel_band_enum_uint8 en_band)
{
    switch (en_band)
    {
        case WLAN_BAND_2G:   /* 2.4GHz */
            return (oal_uint8)MAC_AFFECTED_CHAN_OFFSET_START_FREQ_2;

        case WLAN_BAND_5G:   /* 5GHz */
            return (oal_uint8)MAC_AFFECTED_CHAN_OFFSET_START_FREQ_5;

        default:
            return 0;
    }
}


OAL_STATIC OAL_INLINE oal_bool_enum_uint8  mac_is_rc_dfs_req(mac_regclass_info_stru *pst_rc_info)
{
    if (0 == (pst_rc_info->uc_behaviour_bmap & MAC_RC_DFS))
    {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}


OAL_STATIC OAL_INLINE oal_bool_enum_uint8  mac_is_ch_in_radar_band(mac_rc_start_freq_enum_uint8 en_band, oal_uint8 uc_chan_idx)
{
    mac_regclass_info_stru   *pst_rc_info;

    pst_rc_info = mac_get_channel_idx_rc_info(en_band, uc_chan_idx);
    if (OAL_UNLIKELY(OAL_PTR_NULL == pst_rc_info))
    {
        return OAL_FALSE;
    }

    return mac_is_rc_dfs_req(pst_rc_info);
}


OAL_STATIC OAL_INLINE oal_bool_enum_uint8 mac_is_dfs_channel(oal_uint8 uc_band, oal_uint8 uc_channel_num)
{
    oal_uint8 uc_channel_idx = 0xff;

    if (OAL_SUCC != mac_get_channel_idx_from_num(uc_band, uc_channel_num, &uc_channel_idx))
    {
        return OAL_FALSE;
    }

    if (OAL_FALSE == mac_is_ch_in_radar_band(uc_band, uc_channel_idx))
    {
        return OAL_FALSE;
    }

    return OAL_TRUE;
}


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of mac_regdomain.h */