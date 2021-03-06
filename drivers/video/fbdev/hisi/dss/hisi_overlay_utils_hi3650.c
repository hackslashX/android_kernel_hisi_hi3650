/* Copyright (c) 2013-2014, Hisilicon Tech. Co., Ltd. All rights reserved.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 and
* only version 2 as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
* GNU General Public License for more details.
*
*/

#include "hisi_overlay_utils.h"

uint32_t g_dss_module_base[DSS_CHN_MAX_DEFINE][MODULE_CHN_MAX] = {
	/* D2 */
	{
	MIF_CH0_OFFSET,
	AIF0_CH0_OFFSET,
	AIF1_CH0_OFFSET,
	MCTL_CTL_MUTEX_RCH0,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH0_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH0_OV_OEN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH0_STARTY,
	DSS_MCTRL_SYS_OFFSET + MCTL_MOD0_DBG,
	DSS_RCH_D2_DMA_OFFSET,
	DSS_RCH_D2_DFC_OFFSET,
	0,
	0,
	0,
	0,
	DSS_RCH_D2_CSC_OFFSET,
	0,
	0,
	0,
	0,
	0
	},

	/* D3 */
	{
	MIF_CH1_OFFSET,
	AIF0_CH1_OFFSET,
	AIF1_CH1_OFFSET,
	MCTL_CTL_MUTEX_RCH1,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH1_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH1_OV_OEN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH1_STARTY,
	DSS_MCTRL_SYS_OFFSET + MCTL_MOD1_DBG,
	DSS_RCH_D3_DMA_OFFSET,
	DSS_RCH_D3_DFC_OFFSET,
	0,
	0,
	0,
	0,
	DSS_RCH_D3_CSC_OFFSET,
	0,
	0,
	0,
	0,
	0
	},

	/* V0 */
	{
	MIF_CH2_OFFSET,
	AIF0_CH2_OFFSET,
	AIF1_CH2_OFFSET,
	MCTL_CTL_MUTEX_RCH2,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH2_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH2_OV_OEN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH2_STARTY,
	DSS_MCTRL_SYS_OFFSET + MCTL_MOD2_DBG,
	DSS_RCH_VG0_DMA_OFFSET,
	DSS_RCH_VG0_DFC_OFFSET,
	DSS_RCH_VG0_SCL_OFFSET,
	DSS_RCH_VG0_SCL_LUT_OFFSET,
	DSS_RCH_VG0_SHARPNESS_OFFSET,
	DSS_RCH_VG0_POST_CLIP_OFFSET,
	DSS_RCH_VG0_CSC_OFFSET,
	DSS_RCH_VG0_CE_OFFSET,
	DSS_RCH_VG0_CE0_LUT_OFFSET,
	DSS_RCH_VG0_CE1_LUT_OFFSET,
	DSS_RCH_VG0_CE2_LUT_OFFSET,
	DSS_RCH_VG0_CE3_LUT_OFFSET,
	},

	/* G0 */
	{
	MIF_CH3_OFFSET,
	AIF0_CH3_OFFSET,
	AIF1_CH3_OFFSET,
	MCTL_CTL_MUTEX_RCH3,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH3_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH3_OV_OEN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH3_STARTY,
	DSS_MCTRL_SYS_OFFSET + MCTL_MOD3_DBG,
	DSS_RCH_G0_DMA_OFFSET,
	DSS_RCH_G0_DFC_OFFSET,
	DSS_RCH_G0_SCL_OFFSET,
	0,
	0,
	DSS_RCH_G0_POST_CLIP_OFFSET,
	0,
	0,
	0,
	0,
	0,
	0
	},

	/* V1 */
	{
	MIF_CH4_OFFSET,
	AIF0_CH4_OFFSET,
	AIF1_CH4_OFFSET,
	MCTL_CTL_MUTEX_RCH4,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH4_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH4_OV_OEN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH4_STARTY,
	DSS_MCTRL_SYS_OFFSET + MCTL_MOD4_DBG,
	DSS_RCH_VG1_DMA_OFFSET,
	DSS_RCH_VG1_DFC_OFFSET,
	DSS_RCH_VG1_SCL_OFFSET,
	DSS_RCH_VG1_SCL_LUT_OFFSET,
	DSS_RCH_VG1_SHARPNESS_OFFSET,
	DSS_RCH_VG1_POST_CLIP_OFFSET,
	DSS_RCH_VG1_CSC_OFFSET,
	DSS_RCH_VG1_CE_OFFSET,
	DSS_RCH_VG1_CE0_LUT_OFFSET,
	DSS_RCH_VG1_CE1_LUT_OFFSET,
	DSS_RCH_VG1_CE2_LUT_OFFSET,
	DSS_RCH_VG1_CE3_LUT_OFFSET,
	},

	/* G1 */
	{
	MIF_CH5_OFFSET,
	AIF0_CH5_OFFSET,
	AIF1_CH5_OFFSET,
	MCTL_CTL_MUTEX_RCH5,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH5_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH5_OV_OEN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH5_STARTY,
	DSS_MCTRL_SYS_OFFSET + MCTL_MOD5_DBG,
	DSS_RCH_G1_DMA_OFFSET,
	DSS_RCH_G1_DFC_OFFSET,
	DSS_RCH_G1_SCL_OFFSET,
	0,
	0,
	DSS_RCH_G1_POST_CLIP_OFFSET,
	0,
	0,
	0,
	0,
	0,
	0
	},

	/* D0 */
	{
	MIF_CH6_OFFSET,
	AIF0_CH6_OFFSET,
	AIF1_CH6_OFFSET,
	MCTL_CTL_MUTEX_RCH6,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH6_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH6_OV_OEN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH6_STARTY,
	DSS_MCTRL_SYS_OFFSET + MCTL_MOD6_DBG,
	DSS_RCH_D0_DMA_OFFSET,
	DSS_RCH_D0_DFC_OFFSET,
	0,
	0,
	0,
	0,
	DSS_RCH_D0_CSC_OFFSET,
	0,
	0,
	0,
	0,
	0
	},

	/* D1 */
	{
	MIF_CH7_OFFSET,
	AIF0_CH7_OFFSET,
	AIF1_CH7_OFFSET,
	MCTL_CTL_MUTEX_RCH7,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH7_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH7_OV_OEN,
	DSS_MCTRL_SYS_OFFSET + MCTL_RCH7_STARTY,
	DSS_MCTRL_SYS_OFFSET + MCTL_MOD7_DBG,
	DSS_RCH_D1_DMA_OFFSET,
	DSS_RCH_D1_DFC_OFFSET,
	0,
	0,
	0,
	0,
	DSS_RCH_D1_CSC_OFFSET,
	0,
	0,
	0,
	0,
	0
	},

	/* W0 */
	{
	MIF_CH8_OFFSET,
	AIF0_CH8_OFFSET,
	AIF1_CH8_OFFSET,
	MCTL_CTL_MUTEX_WCH0,
	DSS_MCTRL_SYS_OFFSET + MCTL_WCH0_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_WCH0_OV_IEN,
	0,
	0,
	DSS_WCH0_DMA_OFFSET,
	DSS_WCH0_DFC_OFFSET,
	0,
	0,
	0,
	0,
	DSS_WCH0_CSC_OFFSET,
	0,
	0,
	0,
	0,
	0
	},

	/* W1 */
	{
	MIF_CH9_OFFSET,
	AIF0_CH9_OFFSET,
	AIF1_CH9_OFFSET,
	MCTL_CTL_MUTEX_WCH1,
	DSS_MCTRL_SYS_OFFSET + MCTL_WCH1_FLUSH_EN,
	DSS_MCTRL_SYS_OFFSET + MCTL_WCH1_OV_IEN,
	0,
	0,
	DSS_WCH1_DMA_OFFSET,
	DSS_WCH1_DFC_OFFSET,
	0,
	0,
	0,
	0,
	DSS_WCH1_CSC_OFFSET,
	0,
	0,
	0,
	0,
	0
	},
};

uint32_t g_dss_module_ovl_base[DSS_MCTL_IDX_MAX][MODULE_OVL_MAX] = {
	{DSS_OVL0_OFFSET,
	DSS_MCTRL_CTL0_OFFSET},

	{DSS_OVL1_OFFSET,
	DSS_MCTRL_CTL1_OFFSET},

	{DSS_OVL2_OFFSET,
	DSS_MCTRL_CTL2_OFFSET},

	{DSS_OVL3_OFFSET,
	DSS_MCTRL_CTL3_OFFSET},

	{0,
	0},

	{0,
	0},
};

//SCF_LUT_CHN coef_idx
int g_scf_lut_chn_coef_idx[DSS_CHN_MAX_DEFINE] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};


uint32_t g_dss_module_cap[DSS_CHN_MAX_DEFINE][MODULE_CAP_MAX] = {
	/* D2 */
	{0,0,1,0,0,0,1,0,0,0,1},
	/* D3 */
	{0,0,1,0,0,0,0,0,0,0,1},
	/* V0 */
	{0,1,1,0,1,1,1,0,0,1,1},
	/* G0 */
	{0,1,0,0,0,0,1,0,0,0,0},
	/* V1 */
	{0,1,1,1,0,1,1,0,1,1,1},
	/* G1 */
	{0,1,0,0,0,0,1,0,0,0,0},
	/* D0 */
	{0,0,1,0,0,0,0,0,0,0,1},
	/* D1 */
	{0,0,1,0,0,0,0,0,0,0,1},

	/* W0 */
	{1,0,1,0,0,0,0,1,0,1,1},
	/* W1 */
	{1,0,1,0,0,0,0,1,0,1,1},
};

uint32_t g_dss_mif_sid_map[DSS_CHN_MAX_DEFINE] = {
    0xa, 1, 2, 3, 4, 5, 6, 7, 8, 9
};

uint32_t g_dss_smmu_smrx_idx[DSS_CHN_MAX_DEFINE] = {
    0xa, 1, 2, 3, 4, 5, 6, 7, 8, 9
};

uint32_t g_fpga_flag = 0;
//static int g_dss_module_resource_initialized = 0;
void *g_smmu_rwerraddr_virt = NULL;

static void aif_bw_sort(dss_aif_bw_t a[], int n)
{
	int i = 0;
	int j = 0;
	dss_aif_bw_t tmp;

	for (; i < n; ++i) {
		for (j = i; j < n - 1; ++j) {
			if (a[j].bw > a[j+1].bw) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}

int hisi_dss_aif_handler(struct hisi_fb_data_type *hisifd, dss_overlay_t *pov_req, dss_overlay_block_t *pov_h_block)
{
	int i = 0;
	int k = 0;
	dss_layer_t *layer = NULL;
	dss_wb_layer_t *wb_layer = NULL;
	int chn_idx = 0;
	dss_aif_bw_t *aif_bw = NULL;
	uint32_t tmp = 0;
	uint32_t bw_sum = 0;

	int rch_cnt = 0;
	int axi0_cnt = 0;
	int axi1_cnt = 0;
	dss_aif_bw_t aif_bw_tmp[DSS_CHN_MAX_DEFINE];

	dss_aif_bw_t *aif1_bw = NULL;

	if (NULL == hisifd) {
		HISI_FB_ERR("hisifd is NULL");
		return -EINVAL;
	}
	if (NULL == pov_req) {
		HISI_FB_ERR("pov_req is NULL");
		return -EINVAL;
	}
	if (NULL == pov_h_block) {
		HISI_FB_ERR("pov_h_block is NULL");
		return -EINVAL;
	}

	memset(aif_bw_tmp, 0, sizeof(aif_bw_tmp));

	if (pov_req->wb_enable) {
		for (k = 0; k < pov_req->wb_layer_nums; k++) {
			wb_layer = &(pov_req->wb_layer_infos[k]);
			chn_idx = wb_layer->chn_idx;

			aif_bw = &(hisifd->dss_module.aif_bw[chn_idx]);
			aif_bw->bw = (uint64_t)wb_layer->dst.buf_size *
				(wb_layer->src_rect.w * wb_layer->src_rect.h) / (wb_layer->dst.width * wb_layer->dst.height);
			aif_bw->chn_idx = chn_idx;
			aif_bw->axi_sel = AXI_CHN1;
			aif_bw->is_used = 1;
		}
	}

	rch_cnt = 0;
	//i is not chn_idx, is array idx
	for (i = 0; i < pov_h_block->layer_nums; i++) {
		layer = &pov_h_block->layer_infos[i];
		chn_idx = layer->chn_idx;

		if (layer->need_cap & (CAP_BASE | CAP_DIM | CAP_PURE_COLOR))
			continue;

		//MMBUF
		if (layer->need_cap & CAP_AFBCD) {
			aif1_bw = &(hisifd->dss_module.aif1_bw[chn_idx]);
			aif1_bw->is_used = 1;
			aif1_bw->chn_idx = chn_idx;
			if ((pov_req->ovl_idx == DSS_OVL0) ||
				(pov_req->ovl_idx == DSS_OVL1)) {
				if ((i % 2) == 0) {
					aif1_bw->axi_sel = AXI_CHN0;
				} else {
					aif1_bw->axi_sel = AXI_CHN1;
				}
			} else {
				if ((i % 2) == 0) {
					aif1_bw->axi_sel = AXI_CHN1;
				} else {
					aif1_bw->axi_sel = AXI_CHN0;
				}
			}

			if (g_debug_ovl_online_composer || g_debug_ovl_offline_composer) {
				HISI_FB_INFO("fb%d, aif1, chn_idx=%d, axi_sel=%d.\n",
					hisifd->index, chn_idx, aif1_bw->axi_sel);
			}
		}

		aif_bw_tmp[i].bw = (uint64_t)layer->img.buf_size *
			(layer->src_rect.w * layer->src_rect.h) / (layer->img.width * layer->img.height);
		aif_bw_tmp[i].chn_idx = chn_idx;
		aif_bw_tmp[i].axi_sel = 0;
		aif_bw_tmp[i].is_used = 1;

		bw_sum += aif_bw_tmp[i].bw;
		rch_cnt++;
	}

	//sort
	aif_bw_sort(aif_bw_tmp, rch_cnt);

	//i is not chn_idx, is array idx
	for (i = 0; i < DSS_CHN_MAX_DEFINE; i++) {
		if (aif_bw_tmp[i].is_used != 1)
			continue;

		tmp += aif_bw_tmp[i].bw;

		if ((pov_req->ovl_idx == DSS_OVL0) || (pov_req->ovl_idx == DSS_OVL1)) {
			if (tmp <= (bw_sum / 2)) {
				aif_bw_tmp[i].axi_sel = AXI_CHN0;
				if (axi0_cnt >= AXI0_MAX_DSS_CHN_THRESHOLD) {
					aif_bw_tmp[i - AXI0_MAX_DSS_CHN_THRESHOLD].axi_sel = AXI_CHN1;
					axi1_cnt++;
					axi0_cnt--;
				}
				axi0_cnt++;
			} else {
				aif_bw_tmp[i].axi_sel = AXI_CHN1;
				axi1_cnt++;
			}
		} else {
			if (tmp <= (bw_sum / 2)) {
				aif_bw_tmp[i].axi_sel = AXI_CHN1;
				if (axi1_cnt >= AXI1_MAX_DSS_CHN_THRESHOLD) {
					aif_bw_tmp[i - AXI1_MAX_DSS_CHN_THRESHOLD].axi_sel = AXI_CHN0;
					axi0_cnt++;
					axi1_cnt--;
				}
				axi1_cnt++;
			} else {
				aif_bw_tmp[i].axi_sel = AXI_CHN0;
				axi0_cnt++;
			}
		}

		chn_idx = aif_bw_tmp[i].chn_idx;
		hisifd->dss_module.aif_bw[chn_idx] = aif_bw_tmp[i];

		if (g_debug_ovl_online_composer || g_debug_ovl_offline_composer) {
			HISI_FB_INFO("fb%d, aif0, chn_idx=%d, axi_sel=%d, bw=%llu.\n",
				hisifd->index, chn_idx, aif_bw_tmp[i].axi_sel, aif_bw_tmp[i].bw);
		}
	}

	return 0;
}

void hisi_dss_qos_on(struct hisi_fb_data_type *hisifd)
{
	if (NULL == hisifd) {
		HISI_FB_ERR("hisifd is NULL");
		return;
	}

	outp32(hisifd->noc_dss_base + 0xc, 0x2);
	outp32(hisifd->noc_dss_base + 0x8c, 0x2);
	outp32(hisifd->noc_dss_base + 0x10c, 0x2);
	outp32(hisifd->noc_dss_base + 0x18c, 0x2);
}

/*******************************************************************************
** DSS AIF
*/
void hisi_dss_aif_init(char __iomem *aif_ch_base,
	dss_aif_t *s_aif)
{
	if (NULL == aif_ch_base) {
		HISI_FB_ERR("aif_ch_base is NULL");
		return;
	}
	if (NULL == s_aif) {
		HISI_FB_ERR("s_aif is NULL");
		return;
	}

	memset(s_aif, 0, sizeof(dss_aif_t));

	//s_aif->aif_ch_ctl = inp32(aif_ch_base + AIF_CH_CTL);
	s_aif->aif_ch_ctl = 0x0000F000;
}

void hisi_dss_aif_ch_set_reg(struct hisi_fb_data_type *hisifd,
	char __iomem *aif_ch_base, dss_aif_t *s_aif)
{
	if (hisifd == NULL) {
		HISI_FB_DEBUG("hisifd is NULL!\n");
		return;
	}

	if (aif_ch_base == NULL) {
		HISI_FB_DEBUG("aif_ch_base is NULL!\n");
		return;
	}

	if (s_aif == NULL) {
		HISI_FB_DEBUG("s_aif is NULL!\n");
		return;
	}

	hisifd->set_reg(hisifd, aif_ch_base + AIF_CH_CTL,
		s_aif->aif_ch_ctl, 32, 0);
}

int hisi_dss_aif_ch_config(struct hisi_fb_data_type *hisifd, dss_overlay_t *pov_req,
	dss_layer_t *layer, dss_rect_t *wb_dst_rect, dss_wb_layer_t *wb_layer, int ovl_idx)
{
	dss_aif_t *aif = NULL;
	dss_aif_bw_t *aif_bw = NULL;
	int chn_idx = 0;
	int mid = 0;
	uint32_t credit_step = 0;
	uint64_t dss_core_rate = 0;
	uint32_t scfd_h = 0;
	uint32_t scfd_v = 0;
	uint32_t online_offline_rate = 1;

	if (hisifd == NULL) {
		HISI_FB_ERR("hisifd is NULL Point!");
		return -EINVAL;
	}
	if (pov_req == NULL){
		HISI_FB_ERR("pov_req is NULL Point!");
		return -EINVAL;
	}
	if ((layer == NULL) && (wb_layer == NULL)){
		HISI_FB_ERR("layer & wb_layer is NULL Point!");
		return -EINVAL;
	}
	if ((ovl_idx < DSS_OVL0) || (ovl_idx >= DSS_OVL_IDX_MAX)){
		HISI_FB_ERR("ovl_idx(%d) is invalid!\n", ovl_idx);
		return -EINVAL;
	}

	if (wb_layer) {
		chn_idx = wb_layer->chn_idx;
	} else {
		chn_idx = layer->chn_idx;
	}

	aif = &(hisifd->dss_module.aif[chn_idx]);
	hisifd->dss_module.aif_ch_used[chn_idx] = 1;

	aif_bw = &(hisifd->dss_module.aif_bw[chn_idx]);
	if (aif_bw->is_used != 1) {
		HISI_FB_ERR("fb%d, aif_bw->is_used(%d) is invalid!", hisifd->index, aif_bw->is_used);
		return -EINVAL;
	}

	mid = 0x9 - chn_idx;
	if (mid < 0) {
		HISI_FB_ERR("fb%d, mid(%d) is invalid!", hisifd->index, mid);
		return -EINVAL;
	}

	aif->aif_ch_ctl = set_bits32(aif->aif_ch_ctl, aif_bw->axi_sel, 1, 0);
	aif->aif_ch_ctl = set_bits32(aif->aif_ch_ctl, mid, 4, 4);

	if (g_fpga_flag == 0) {
		if ((ovl_idx == DSS_OVL2) || (ovl_idx == DSS_OVL3)) {
			if (layer) {
				dss_core_rate = hisifd->dss_clk_rate.dss_pri_clk_rate;
				if (dss_core_rate == 0) {
					HISI_FB_ERR("fb%d, dss_core_rate(%llu) is invalid!",
						hisifd->index, dss_core_rate);
					dss_core_rate = DEFAULT_DSS_CORE_CLK_RATE;
				}

				if ((layer->src_rect.w > layer->dst_rect.w) &&
					(layer->src_rect.w > get_panel_xres(hisifd))) {
					scfd_h = layer->src_rect.w * 100 / get_panel_xres(hisifd);
				} else {
					scfd_h = 100;
				}

				//after stretch
				if (layer->src_rect.h > layer->dst_rect.h) {
					scfd_v = layer->src_rect.h * 100 / layer->dst_rect.h;
				} else {
					scfd_v = 100;
				}

				if (pov_req->wb_compose_type == DSS_WB_COMPOSE_COPYBIT) {
					if (wb_dst_rect) {
						online_offline_rate = wb_dst_rect->w * wb_dst_rect->h /
							(hisifd->panel_info.xres * hisifd->panel_info.yres);
					}

					if (online_offline_rate == 0)
						online_offline_rate = 1;
				}

				//credit_step = pix_f*128/(core_f*16/4)*scfd_h*scfd_v
				credit_step = hisifd->panel_info.pxl_clk_rate * online_offline_rate * 32 * scfd_h * scfd_v /
						dss_core_rate  / (100 * 100);

				if (g_debug_ovl_online_composer || g_debug_ovl_offline_composer || g_debug_ovl_credit_step) {
					HISI_FB_INFO("fb%d, layer_idx(%d), chn_idx(%d), src_rect(%d,%d,%d,%d),"
						"dst_rect(%d,%d,%d,%d), scfd_h=%d, scfd_v=%d, credit_step=%d.\n",
						hisifd->index, layer->layer_idx, layer->chn_idx,
						layer->src_rect.x, layer->src_rect.y, layer->src_rect.w, layer->src_rect.h,
						layer->dst_rect.x, layer->dst_rect.y, layer->dst_rect.w, layer->dst_rect.h,
						scfd_h, scfd_v, credit_step);
				}

				if (credit_step < 32) {
					credit_step = 32;
				}

				if (credit_step > 64) {
					credit_step = 0;
				}

				aif->aif_ch_ctl = set_bits32(aif->aif_ch_ctl, 0x1, 1, 11);
				aif->aif_ch_ctl = set_bits32(aif->aif_ch_ctl, credit_step, 7, 16);
			}
		}
	} else {
		if (chn_idx >= DSS_WCHN_W0) {
			aif->aif_ch_ctl = set_bits32(aif->aif_ch_ctl, 0x1, 1, 11);
			if (wb_layer && (wb_layer->need_cap & CAP_AFBCE)) {
				aif->aif_ch_ctl = set_bits32(aif->aif_ch_ctl, 0x1, 2, 8);
			}
			aif->aif_ch_ctl = set_bits32(aif->aif_ch_ctl, 0x20, 7, 16);
		}
	}

	return 0;
}

int hisi_dss_aif1_ch_config(struct hisi_fb_data_type *hisifd, dss_overlay_t *pov_req,
	dss_layer_t *layer, dss_wb_layer_t *wb_layer, int ovl_idx)
{
	dss_aif_t *aif1 = NULL;
	dss_aif_bw_t *aif1_bw = NULL;
	int chn_idx = 0;
	uint32_t need_cap = 0;
	int mid = 0;
	uint32_t credit_step = 0;
	uint64_t dss_core_rate = 0;
	uint32_t scfd_h = 0;
	uint32_t scfd_v = 0;

	if (hisifd == NULL) {
		HISI_FB_ERR("hisifd is NULL Point!");
		return -EINVAL;
	}
	if (pov_req == NULL){
		HISI_FB_ERR("pov_req is NULL Point!");
		return -EINVAL;
	}
	if ((layer == NULL) && (wb_layer == NULL)){
		HISI_FB_ERR("layer & wb_layer is NULL Point!");
		return -EINVAL;
	}
	if ((ovl_idx < DSS_OVL0) || (ovl_idx >= DSS_OVL_IDX_MAX)){
		HISI_FB_ERR("ovl_idx(%d) is invalid!\n", ovl_idx);
		return -EINVAL;
	}

	if (wb_layer) {
		chn_idx = wb_layer->chn_idx;
		need_cap = wb_layer->need_cap;
	} else {
		chn_idx = layer->chn_idx;
		need_cap = layer->need_cap;
	}

	if (!(need_cap & CAP_AFBCD))
		return 0;

	aif1 = &(hisifd->dss_module.aif1[chn_idx]);
	hisifd->dss_module.aif1_ch_used[chn_idx] = 1;

	aif1_bw = &(hisifd->dss_module.aif1_bw[chn_idx]);
	if (aif1_bw->is_used != 1) {
		HISI_FB_ERR("fb%d, aif1_bw->is_used=%d no equal to 1 is err!", hisifd->index, aif1_bw->is_used);
		return 0;
	}

	mid = 0x9 - chn_idx;
	if (mid < 0) {
		HISI_FB_ERR("fb%d, mid=%d is invalid!", hisifd->index, mid);
		return 0;
	}

	aif1->aif_ch_ctl = set_bits32(aif1->aif_ch_ctl, aif1_bw->axi_sel, 1, 0);
	aif1->aif_ch_ctl = set_bits32(aif1->aif_ch_ctl, mid, 4, 4);

	if (g_fpga_flag == 0) {
		if ((ovl_idx == DSS_OVL0) || (ovl_idx == DSS_OVL1)) {
			if (layer && (layer->need_cap & CAP_AFBCD)) {
				dss_core_rate = hisifd->dss_clk_rate.dss_pri_clk_rate;
				if (dss_core_rate == 0) {
					HISI_FB_ERR("fb%d, dss_core_rate(%llu) is invalid!",
						hisifd->index, dss_core_rate);
					dss_core_rate = DEFAULT_DSS_CORE_CLK_RATE;
				}

				if ((layer->src_rect.w > layer->dst_rect.w) &&
					(layer->src_rect.w > get_panel_xres(hisifd))) {
					scfd_h = layer->src_rect.w * 100 / get_panel_xres(hisifd);
				} else {
					scfd_h = 100;
				}

				//after stretch
				if (layer->src_rect.h > layer->dst_rect.h) {
					scfd_v = layer->src_rect.h * 100 / layer->dst_rect.h;
				} else {
					scfd_v = 100;
				}

				//credit_step = pix_f*128/(core_f*16/4)*1.25*scfd_h*scfd_v
				credit_step = hisifd->panel_info.pxl_clk_rate * 32 * 150 * scfd_h * scfd_v /
					dss_core_rate  / (100 * 100 * 100);

				if (g_debug_ovl_online_composer || g_debug_ovl_offline_composer || g_debug_ovl_credit_step) {
					HISI_FB_INFO("fb%d, layer_idx(%d), chn_idx(%d), src_rect(%d,%d,%d,%d),"
						"dst_rect(%d,%d,%d,%d), scfd_h=%d, scfd_v=%d, credit_step=%d.\n",
						hisifd->index, layer->layer_idx, layer->chn_idx,
						layer->src_rect.x, layer->src_rect.y, layer->src_rect.w, layer->src_rect.h,
						layer->dst_rect.x, layer->dst_rect.y, layer->dst_rect.w, layer->dst_rect.h,
						scfd_h, scfd_v, credit_step);
				}

				if (credit_step < 32) {
					credit_step = 32;
				}

				if (credit_step > 64) {
					credit_step = 0;
				}

				aif1->aif_ch_ctl = set_bits32(aif1->aif_ch_ctl, 0x1, 1, 11);
				aif1->aif_ch_ctl = set_bits32(aif1->aif_ch_ctl, credit_step, 7, 16);
			}
		} else {
			if (layer && (layer->need_cap & CAP_AFBCD)) {
				dss_core_rate = hisifd->dss_clk_rate.dss_pri_clk_rate;
				if (dss_core_rate == 0) {
					HISI_FB_ERR("fb%d, dss_core_rate(%llu is invalid!",
						hisifd->index, dss_core_rate);
					dss_core_rate = DEFAULT_DSS_CORE_CLK_RATE;
				}

				if ((layer->src_rect.w > layer->dst_rect.w) &&
					(layer->src_rect.w > get_panel_xres(hisifd))) {
					scfd_h = layer->src_rect.w * 100 / get_panel_xres(hisifd);
				} else {
					scfd_h = 100;
				}

				//after stretch
				if (layer->src_rect.h > layer->dst_rect.h) {
					scfd_v = layer->src_rect.h * 100 / layer->dst_rect.h;
				} else {
					scfd_v = 100;
				}

				//credit_step = pix_f*128/(core_f*16/4)*scfd_h*scfd_v
				credit_step = hisifd->panel_info.pxl_clk_rate * 32 * scfd_h * scfd_v /
					dss_core_rate  / (100 * 100);

				if (g_debug_ovl_online_composer || g_debug_ovl_offline_composer || g_debug_ovl_credit_step) {
					HISI_FB_INFO("fb%d, layer_idx(%d), chn_idx(%d), src_rect(%d,%d,%d,%d),"
						"dst_rect(%d,%d,%d,%d), scfd_h=%d, scfd_v=%d, credit_step=%d.\n",
						hisifd->index, layer->layer_idx, layer->chn_idx,
						layer->src_rect.x, layer->src_rect.y, layer->src_rect.w, layer->src_rect.h,
						layer->dst_rect.x, layer->dst_rect.y, layer->dst_rect.w, layer->dst_rect.h,
						scfd_h, scfd_v, credit_step);
				}

				if (credit_step < 32) {
					credit_step = 32;
				}

				if (credit_step > 64) {
					credit_step = 0;
				}

				aif1->aif_ch_ctl = set_bits32(aif1->aif_ch_ctl, 0x1, 1, 11);
				aif1->aif_ch_ctl = set_bits32(aif1->aif_ch_ctl, credit_step, 7, 16);
			}
		}
	} else {
		if ((ovl_idx == DSS_OVL2) || (ovl_idx == DSS_OVL3)) {
			aif1->aif_ch_ctl = set_bits32(aif1->aif_ch_ctl, 0x1, 1, 11);
			aif1->aif_ch_ctl = set_bits32(aif1->aif_ch_ctl, 0x10, 7, 16);
		}
	}

	return 0;
}


/*******************************************************************************
** DSS SMMU
*/
void hisi_dss_smmu_on(struct hisi_fb_data_type *hisifd)
{
	char __iomem *smmu_base = NULL;
	int idx0 = 0;
	int idx1 = 0;
	int idx2 = 0;
	int idx3 = 0;
	uint32_t phy_pgd_base = 0;
	struct iommu_domain_data *domain_data = NULL;
	uint64_t smmu_rwerraddr_phys = 0;

	if (NULL == hisifd) {
		HISI_FB_ERR("hisifd is NULL");
		return;
	}

	smmu_base = hisifd->dss_base + DSS_SMMU_OFFSET;

	set_reg(smmu_base + SMMU_SCR, 0x0, 1, 0);
	set_reg(smmu_base + SMMU_SCR, 0x7, 3, 3);
	set_reg(smmu_base + SMMU_SCR, g_dss_smmu_outstanding - 1, 4, 16);
	set_reg(smmu_base + SMMU_SCR, 0x1, 8, 20);

	//auto_clk_gt_en
	set_reg(smmu_base + SMMU_LP_CTRL, 0x1, 1, 0);
	//Short Descriptor
	set_reg(smmu_base + SMMU_CB_TTBCR, 0x0, 1, 0);

	//RWERRADDR
	if (g_smmu_rwerraddr_virt) {
		smmu_rwerraddr_phys = virt_to_phys(g_smmu_rwerraddr_virt);

		set_reg(smmu_base + SMMU_ERR_RDADDR,
			(uint32_t)(smmu_rwerraddr_phys & 0xFFFFFFFF), 32, 0);
		//set_reg(smmu_base + SMMU_ADDR_MSB,
		//	(uint32_t)((smmu_rwerraddr_phys >> 32) & 0x3), 2, 0);
		set_reg(smmu_base + SMMU_ERR_WRADDR,
			(uint32_t)(smmu_rwerraddr_phys & 0xFFFFFFFF), 32, 0);
		//set_reg(smmu_base + SMMU_ADDR_MSB,
		//	(uint32_t)((smmu_rwerraddr_phys >> 32) & 0x3), 2, 2);
	} else {
		set_reg(smmu_base + SMMU_ERR_RDADDR, 0x7FF00000, 32, 0);
		//set_reg(smmu_base + SMMU_ADDR_MSB, 0x0, 2, 0);
		set_reg(smmu_base + SMMU_ERR_WRADDR, 0x7FFF0000, 32, 0);
		//set_reg(smmu_base + SMMU_ADDR_MSB, 0x0, 2, 2);
	}

	//cmdlist
	set_reg(smmu_base + SMMU_RLD_EN0, DSS_SMMU_RLD_EN0_DEFAULT_VAL, 32, 0);
	set_reg(smmu_base + SMMU_RLD_EN1, DSS_SMMU_RLD_EN1_DEFAULT_VAL, 32, 0);

	/*
	idx0 = (0 << 4); //chn | (0 << 4)
	idx1 = (1 << 4);
	idx2 = (2 << 4);
	idx3 = (3 << 4);
	*/
	idx0 = (0 << 4); //chn | (0 << 4)
	idx1 = idx0 + DSS_MIF_SMMU_SMRX_IDX_STEP;
	idx2 = idx1 + DSS_MIF_SMMU_SMRX_IDX_STEP;
	idx3 = idx2 + DSS_MIF_SMMU_SMRX_IDX_STEP;

	set_reg(smmu_base + SMMU_SMRx + idx0 * 0x4, 0x9, 32, 0);
	set_reg(smmu_base + SMMU_SMRx + idx1 * 0x4, 0x9, 32, 0);
	set_reg(smmu_base + SMMU_SMRx + idx2 * 0x4, 0x9, 32, 0);
	set_reg(smmu_base + SMMU_SMRx + idx3 * 0x4, 0x9, 32, 0);

	//TTBR0
	domain_data = (struct iommu_domain_data *)(hisifd->hisi_domain->priv);
	phy_pgd_base = (uint32_t)(domain_data->phy_pgd_base);
	set_reg(smmu_base + SMMU_CB_TTBR0, phy_pgd_base, 32, 0);
}

void hisi_dss_smmu_init(char __iomem *smmu_base,
	dss_smmu_t *s_smmu)
{
	if (NULL == smmu_base) {
		HISI_FB_ERR("smmu_base is NULL");
		return;
	}
	if (NULL == s_smmu) {
		HISI_FB_ERR("s_smmu is NULL");
		return;
	}

	memset(s_smmu, 0, sizeof(dss_smmu_t));
}

void hisi_dss_smmu_ch_set_reg(struct hisi_fb_data_type *hisifd,
	char __iomem *smmu_base, dss_smmu_t *s_smmu, int chn_idx)
{
	int idx0 = 0;
	int idx1 = 0;
	int idx2 = 0;
	int idx3 = 0;

	if (hisifd == NULL) {
		HISI_FB_DEBUG("hisifd is NULL!\n");
		return;
	}

	if (smmu_base == NULL) {
		HISI_FB_DEBUG("smmu_base is NULL!\n");
		return;
	}

	if (s_smmu == NULL) {
		HISI_FB_DEBUG("s_smmu is NULL!\n");
		return;
	}

	/*
	if (chn_idx == DSS_RCHN_D2) {
		idx0 = 0xA | (0 << 4);
		idx1 = 0xA | (1 << 4);
		idx2 = 0xA | (2 << 4);
		idx3 = 0xA | (3 << 4);
	} else {
		idx0 = chn_idx | (0 << 4);
		idx1 = chn_idx | (1 << 4);
		idx2 = chn_idx | (2 << 4);
		idx3 = chn_idx | (3 << 4);
	}*/
	idx0 = g_dss_smmu_smrx_idx[chn_idx];
	idx1 = idx0 + DSS_MIF_SMMU_SMRX_IDX_STEP;
	idx2 = idx1 + DSS_MIF_SMMU_SMRX_IDX_STEP;
	idx3 = idx2 + DSS_MIF_SMMU_SMRX_IDX_STEP;

	if ((idx0 < 0) || (idx0 >= SMMU_SID_NUM)) {
		HISI_FB_ERR("idx0 is invalid");
		return;
	}
	if ((idx1 < 0) || (idx1 >= SMMU_SID_NUM)) {
		HISI_FB_ERR("idx1 is invalid");
		return;
	}
	if ((idx2 < 0) || (idx2 >= SMMU_SID_NUM)) {
		HISI_FB_ERR("idx2 is invalid");
		return;
	}
	if ((idx3 < 0) || (idx3 >= SMMU_SID_NUM)) {
		HISI_FB_ERR("idx3 is invalid");
		return;
	}

	if (s_smmu->smmu_smrx_used[chn_idx] == 1) {
		hisifd->set_reg(hisifd, smmu_base + SMMU_SMRx + idx0 * 0x4,
			s_smmu->smmu_smrx[idx0], 32, 0);
		hisifd->set_reg(hisifd, smmu_base + SMMU_SMRx + idx1 * 0x4,
			s_smmu->smmu_smrx[idx1], 32, 0);
		hisifd->set_reg(hisifd, smmu_base + SMMU_SMRx + idx2 * 0x4,
			s_smmu->smmu_smrx[idx2], 32, 0);
		hisifd->set_reg(hisifd, smmu_base + SMMU_SMRx + idx3 * 0x4,
			s_smmu->smmu_smrx[idx3], 32, 0);
	}
}


int hisi_dss_smmu_ch_config(struct hisi_fb_data_type *hisifd,
	dss_layer_t *layer, dss_wb_layer_t *wb_layer)
{
	dss_smmu_t *smmu = NULL;
	int chn_idx = 0;
	dss_img_t *img = NULL;
	int idx0 = 0;
	int idx1 = 0;
	int idx2 = 0;
	int idx3 = 0;

	if (NULL == hisifd) {
		HISI_FB_ERR("hisifd is NULL");
		return -EINVAL;
	}
	if ((layer == NULL) && (wb_layer == NULL)) {
		HISI_FB_ERR("layer or wb_layer is NULL");
		return -EINVAL;
	}

	if (wb_layer) {
		img = &(wb_layer->dst);
		chn_idx = wb_layer->chn_idx;
	} else {
		img = &(layer->img);
		chn_idx = layer->chn_idx;
	}

	smmu = &(hisifd->dss_module.smmu);
	hisifd->dss_module.smmu_used = 1;

	idx0 = g_dss_smmu_smrx_idx[chn_idx];
	idx1 = idx0 + DSS_MIF_SMMU_SMRX_IDX_STEP;
	idx2 = idx1 + DSS_MIF_SMMU_SMRX_IDX_STEP;
	idx3 = idx2 + DSS_MIF_SMMU_SMRX_IDX_STEP;
	/*if (chn_idx == DSS_RCHN_D2) {
		idx0 = 0xA | (0 << 4);
		idx1 = 0xA | (1 << 4);
		idx2 = 0xA | (2 << 4);
		idx3 = 0xA | (3 << 4);
	} else {
		idx0 = chn_idx | (0 << 4);
		idx1 = chn_idx | (1 << 4);
		idx2 = chn_idx | (2 << 4);
		idx3 = chn_idx | (3 << 4);
	}*/

	if ((idx0 < 0) || (idx0 >= SMMU_SID_NUM)) {
		HISI_FB_ERR("idx0 is invalid");
		return -EINVAL;
	}
	if ((idx1 < 0) || (idx1>= SMMU_SID_NUM)) {
		HISI_FB_ERR("idx1 is invalid");
		return -EINVAL;
	}
	if ((idx2 < 0) || (idx2 >= SMMU_SID_NUM)) {
		HISI_FB_ERR("idx2 is invalid");
		return -EINVAL;
	}
	if ((idx3 < 0) || (idx3 >= SMMU_SID_NUM)) {
		HISI_FB_ERR("idx3 is invalid");
		return -EINVAL;
	}

	smmu->smmu_smrx_used[chn_idx] = 1;

	if (img->mmu_enable == 0) {
		smmu->smmu_smrx[idx0] = set_bits32(smmu->smmu_smrx[idx0], 0x9, 4, 0);
		smmu->smmu_smrx[idx1] = set_bits32(smmu->smmu_smrx[idx1], 0x9, 4, 0);
		smmu->smmu_smrx[idx2] = set_bits32(smmu->smmu_smrx[idx2], 0x9, 4, 0);
		smmu->smmu_smrx[idx3] = set_bits32(smmu->smmu_smrx[idx3], 0x9, 4, 0);
	} else {
		smmu->smmu_smrx[idx0] = set_bits32(smmu->smmu_smrx[idx0], 0x0, 1, 0);
		smmu->smmu_smrx[idx0] = set_bits32(smmu->smmu_smrx[idx0], 0x1, 1, 3);
		smmu->smmu_smrx[idx0] = set_bits32(smmu->smmu_smrx[idx0], 0x1, 1, 4);
		smmu->smmu_smrx[idx0] = set_bits32(smmu->smmu_smrx[idx0], 0x3, 7, 5);

		smmu->smmu_smrx[idx1] = set_bits32(smmu->smmu_smrx[idx1], 0x0, 1, 0);
		smmu->smmu_smrx[idx1] = set_bits32(smmu->smmu_smrx[idx1], 0x1, 1, 3);
		smmu->smmu_smrx[idx1] = set_bits32(smmu->smmu_smrx[idx1], 0x1, 1, 4);
		smmu->smmu_smrx[idx1] = set_bits32(smmu->smmu_smrx[idx1], 0x3, 7, 5);

		smmu->smmu_smrx[idx2] = set_bits32(smmu->smmu_smrx[idx2], 0x0, 1, 0);
		smmu->smmu_smrx[idx2] = set_bits32(smmu->smmu_smrx[idx2], 0x1, 1, 3);
		smmu->smmu_smrx[idx2] = set_bits32(smmu->smmu_smrx[idx2], 0x1, 1, 4);
		smmu->smmu_smrx[idx2] = set_bits32(smmu->smmu_smrx[idx2], 0x3, 7, 5);

		smmu->smmu_smrx[idx3] = set_bits32(smmu->smmu_smrx[idx3], 0x0, 1, 0);
		smmu->smmu_smrx[idx3] = set_bits32(smmu->smmu_smrx[idx3], 0x1, 1, 3);
		smmu->smmu_smrx[idx3] = set_bits32(smmu->smmu_smrx[idx3], 0x1, 1, 4);
		smmu->smmu_smrx[idx3] = set_bits32(smmu->smmu_smrx[idx3], 0x3, 7, 5);
	}

	return 0;
}

/*
** the minimun value of afbce&rot is 256
*/
void hisifb_adjust_block_rect(int block_num, dss_rect_t *ov_block_rects[], dss_wb_layer_t *wb_layer)
{
	int i = 0;
	dss_rect_t block_rect;
	bool need_adjust_block = false;

	if (NULL == ov_block_rects) {
		HISI_FB_ERR("ov_block_rects is NULL");
		return;
	}
	if (NULL == wb_layer) {
		HISI_FB_ERR("wb_layer is NULL");
		return;
	}

	if ((block_num > 1) && (ov_block_rects[block_num - 1]->w < HISI_DSS_MIN_ROT_AFBCE_BLOCK_SIZE)) {
		if ((wb_layer->transform == (HISI_FB_TRANSFORM_ROT_90 | HISI_FB_TRANSFORM_FLIP_V))
			&& (wb_layer->need_cap == CAP_AFBCE)) {
			if (g_debug_ovl_block_composer) {
				HISI_FB_INFO("before_adjust:ov_block_rects[%d]:[%d:%d:%d:%d]\n",
					block_num - 1, ov_block_rects[block_num-1]->x, ov_block_rects[block_num-1]->y, ov_block_rects[block_num-1]->w,
					ov_block_rects[block_num-1]->h);
			}

			block_rect = *ov_block_rects[block_num - 1];

			ov_block_rects[block_num - 1]->w += HISI_DSS_MIN_ROT_AFBCE_BLOCK_SIZE;
			if (ov_block_rects[block_num - 1]->w > HISI_DSS_MAX_ROT_AFBCE_BLOCK_SIZE) {
				ov_block_rects[block_num - 1]->w = HISI_DSS_MAX_ROT_AFBCE_BLOCK_SIZE;
			}

			block_rect.x -= ov_block_rects[block_num - 1]->w - block_rect.w;
			ov_block_rects[block_num - 1]->x = ALIGN_UP(block_rect.x, AFBC_BLOCK_ALIGN);
			ov_block_rects[block_num - 1]->w -= ov_block_rects[block_num - 1]->x - block_rect.x;

			need_adjust_block = true;
		}
	}

	if (need_adjust_block && g_debug_ovl_block_composer) {
		for (i = 0; i < block_num; i++) {
			HISI_FB_INFO("after_adjust:ov_block_rects[%d]:[%d:%d:%d:%d]\n",
				i, ov_block_rects[i]->x, ov_block_rects[i]->y, ov_block_rects[i]->w,
				ov_block_rects[i]->h);
		}
	}
}

/*******************************************************************************
** DSS CSC
*/
#define CSC_ROW	(3)
#define CSC_COL	(5)

/*
** Rec.601 for Computer
** [ p00 p01 p02 cscidc2 cscodc2 ]
** [ p10 p11 p12 cscidc1 cscodc1 ]
** [ p20 p21 p22 cscidc0 cscodc0 ]
*/
static int CSC_COE_YUV2RGB601_NARROW[CSC_ROW][CSC_COL] = {
	{0x12a, 0x000, 0x199, 0x1f0, 0x0},
	{0x12a, 0x79d, 0x731, 0x180, 0x0},
	{0x12a, 0x205, 0x000, 0x180, 0x0}
};

static int CSC_COE_RGB2YUV601_NARROW[CSC_ROW][CSC_COL] = {
	{0x042, 0x081, 0x019, 0x0, 0x010},
	{0x7DB, 0x7B7, 0x070, 0x0, 0x080},
	{0x070, 0x7A3, 0x7EF, 0x0, 0x080}
};

static int CSC_COE_YUV2RGB709_NARROW[CSC_ROW][CSC_COL] = {
	{0x12A, 0x000, 0x1CB, 0x1F0, 0x0},
	{0x12A, 0x7CA, 0x778, 0x180, 0x0},
	{0x12A, 0x21D, 0x000, 0x180, 0x0}
};

static int CSC_COE_RGB2YUV709_NARROW[CSC_ROW][CSC_COL] = {
	{0x02F, 0x09D, 0x010, 0x0, 0x010},
	{0x7E7, 0x7AA, 0x070, 0x0, 0x080},
	{0x070, 0x79B, 0x7F7, 0x0, 0x080}
};


static int CSC_COE_YUV2RGB601_WIDE[CSC_ROW][CSC_COL] = {
	{0x100, 0x000, 0x15f, 0x000, 0x0},
	{0x100, 0x7ab, 0x74e, 0x180, 0x0},
	{0x100, 0x1bb, 0x000, 0x180, 0x0}
};

static int CSC_COE_RGB2YUV601_WIDE[CSC_ROW][CSC_COL] = {
	{0x04d, 0x096, 0x01d, 0x0, 0x000},
	{0x7d5, 0x79b, 0x083, 0x0, 0x080},
	{0x083, 0x793, 0x7ec, 0x0, 0x080},
};

static int CSC_COE_YUV2RGB709_WIDE[CSC_ROW][CSC_COL] = {
	{0x100, 0x000, 0x18a, 0x000, 0x0},
	{0x100, 0x7d2, 0x78b, 0x180, 0x0},
	{0x100, 0x1d1, 0x000, 0x180, 0x0},
};

static int CSC_COE_RGB2YUV709_WIDE[CSC_ROW][CSC_COL] = {
	{0x037, 0x0b7, 0x012, 0x0, 0x000},
	{0x7e3, 0x79c, 0x083, 0x0, 0x080},
	{0x083, 0x78a, 0x7f5, 0x0, 0x080},
};

void hisi_dss_csc_init(char __iomem *csc_base, dss_csc_t *s_csc)
{
	if (NULL == csc_base) {
		HISI_FB_ERR("csc_base is NULL");
		return;
	}
	if (NULL == s_csc) {
		HISI_FB_ERR("s_csc is NULL");
		return;
	}

	memset(s_csc, 0, sizeof(dss_csc_t));

	s_csc->idc = inp32(csc_base + CSC_IDC);
	s_csc->odc = inp32(csc_base + CSC_ODC);
	s_csc->p0 = inp32(csc_base + CSC_P0);
	s_csc->p1 = inp32(csc_base + CSC_P1);
	s_csc->p2 = inp32(csc_base + CSC_P2);
	s_csc->p3 = inp32(csc_base + CSC_P3);
	s_csc->p4 = inp32(csc_base + CSC_P4);
	s_csc->icg_module = inp32(csc_base + CSC_ICG_MODULE);
}

void hisi_dss_csc_set_reg(struct hisi_fb_data_type *hisifd,
	char __iomem *csc_base, dss_csc_t *s_csc)
{
	if (hisifd == NULL) {
		HISI_FB_DEBUG("hisifd is NULL!\n");
		return;
	}

	if (csc_base == NULL) {
		HISI_FB_DEBUG("csc_base is NULL!\n");
		return;
	}

	if (s_csc == NULL) {
		HISI_FB_DEBUG("s_csc is NULL!\n");
		return;
	}

	hisifd->set_reg(hisifd, csc_base + CSC_IDC, s_csc->idc, 32, 0);
	hisifd->set_reg(hisifd, csc_base + CSC_ODC, s_csc->odc, 32, 0);
	hisifd->set_reg(hisifd, csc_base + CSC_P0, s_csc->p0, 32, 0);
	hisifd->set_reg(hisifd, csc_base + CSC_P1, s_csc->p1, 32, 0);
	hisifd->set_reg(hisifd, csc_base + CSC_P2, s_csc->p2, 32, 0);
	hisifd->set_reg(hisifd, csc_base + CSC_P3, s_csc->p3, 32, 0);
	hisifd->set_reg(hisifd, csc_base + CSC_P4, s_csc->p4, 32, 0);
	hisifd->set_reg(hisifd, csc_base + CSC_ICG_MODULE, s_csc->icg_module, 32, 0);
}

int hisi_dss_csc_config(struct hisi_fb_data_type *hisifd,
	dss_layer_t *layer, dss_wb_layer_t *wb_layer)
{
	dss_csc_t *csc = NULL;
	int chn_idx = 0;
	uint32_t format = 0;
	uint32_t csc_mode = 0;
	int (*csc_coe_yuv2rgb)[CSC_COL];
	int (*csc_coe_rgb2yuv)[CSC_COL];

	if (hisifd == NULL) {
		HISI_FB_ERR("hisifd is NULL Point!");
		return -EINVAL;
	}

	if (wb_layer) {
		chn_idx = wb_layer->chn_idx;
		format = wb_layer->dst.format;
		csc_mode = wb_layer->dst.csc_mode;
	} else {
		if (layer) {
			chn_idx = layer->chn_idx;
			format = layer->img.format;
			csc_mode = layer->img.csc_mode;
		}
	}

	if (!isYUV(format))
		return 0;

	if (csc_mode == DSS_CSC_601_WIDE) {
		csc_coe_yuv2rgb = CSC_COE_YUV2RGB601_WIDE;
		csc_coe_rgb2yuv = CSC_COE_RGB2YUV601_WIDE;
	} else if (csc_mode == DSS_CSC_601_NARROW) {
		csc_coe_yuv2rgb = CSC_COE_YUV2RGB601_NARROW;
		csc_coe_rgb2yuv = CSC_COE_RGB2YUV601_NARROW;
	} else if (csc_mode == DSS_CSC_709_WIDE) {
		csc_coe_yuv2rgb = CSC_COE_YUV2RGB709_WIDE;
		csc_coe_rgb2yuv = CSC_COE_RGB2YUV709_WIDE;
	} else if (csc_mode == DSS_CSC_709_NARROW) {
		csc_coe_yuv2rgb = CSC_COE_YUV2RGB709_NARROW;
		csc_coe_rgb2yuv = CSC_COE_RGB2YUV709_NARROW;
	} else {
		HISI_FB_ERR("not support this csc_mode(%d)!\n", csc_mode);
		csc_coe_yuv2rgb = CSC_COE_YUV2RGB601_WIDE;
		csc_coe_rgb2yuv = CSC_COE_RGB2YUV601_WIDE;
	}

	csc = &(hisifd->dss_module.csc[chn_idx]);
	hisifd->dss_module.csc_used[chn_idx] = 1;

	if (layer) {
		csc->idc = set_bits32(csc->idc, 0x1, 1, 27);
		csc->idc = set_bits32(csc->idc,
			(csc_coe_yuv2rgb[2][3] |
			(csc_coe_yuv2rgb[1][3] << 9) |
			(csc_coe_yuv2rgb[0][3] << 18)), 27, 0);

		csc->odc = set_bits32(csc->odc,
			(csc_coe_yuv2rgb[2][4] |
			(csc_coe_yuv2rgb[1][4] << 9) |
			(csc_coe_yuv2rgb[0][4] << 18)), 27, 0);

		csc->p0 = set_bits32(csc->p0, csc_coe_yuv2rgb[0][0], 11, 0);
		csc->p0 = set_bits32(csc->p0, csc_coe_yuv2rgb[0][1], 11, 16);

		csc->p1 = set_bits32(csc->p1, csc_coe_yuv2rgb[0][2], 11, 0);
		csc->p1 = set_bits32(csc->p1, csc_coe_yuv2rgb[1][0], 11, 16);

		csc->p2 = set_bits32(csc->p2, csc_coe_yuv2rgb[1][1], 11, 0);
		csc->p2 = set_bits32(csc->p2, csc_coe_yuv2rgb[1][2], 11, 16);

		csc->p3 = set_bits32(csc->p3, csc_coe_yuv2rgb[2][0], 11, 0);
		csc->p3 = set_bits32(csc->p3, csc_coe_yuv2rgb[2][1], 11, 16);

		csc->p4 = set_bits32(csc->p4, csc_coe_yuv2rgb[2][2], 11, 0);
	}

	if (wb_layer) {
		csc->idc = set_bits32(csc->idc, 0x1, 1, 27);
		csc->idc = set_bits32(csc->idc,
			(csc_coe_rgb2yuv[2][3] |
			(csc_coe_rgb2yuv[1][3] << 9) |
			(csc_coe_rgb2yuv[0][3] << 18)), 27, 0);

		csc->odc = set_bits32(csc->odc,
			(csc_coe_rgb2yuv[2][4] |
			(csc_coe_rgb2yuv[1][4] << 9) |
			(csc_coe_rgb2yuv[0][4] << 18)), 27, 0);

		csc->p0 = set_bits32(csc->p0, csc_coe_rgb2yuv[0][0], 11, 0);
		csc->p0 = set_bits32(csc->p0, csc_coe_rgb2yuv[0][1], 11, 16);

		csc->p1 = set_bits32(csc->p1, csc_coe_rgb2yuv[0][2], 11, 0);
		csc->p1 = set_bits32(csc->p1, csc_coe_rgb2yuv[1][0], 11, 16);

		csc->p2 = set_bits32(csc->p2, csc_coe_rgb2yuv[1][1], 11, 0);
		csc->p2 = set_bits32(csc->p2, csc_coe_rgb2yuv[1][2], 11, 16);

		csc->p3 = set_bits32(csc->p3, csc_coe_rgb2yuv[2][0], 11, 0);
		csc->p3 = set_bits32(csc->p3, csc_coe_rgb2yuv[2][1], 11, 16);

		csc->p4 = set_bits32(csc->p4, csc_coe_rgb2yuv[2][2], 27, 0);
	}

	csc->icg_module = set_bits32(csc->icg_module, 0x1, 1, 0);

	return 0;
}

/*lint -e679 -e730 -e732*/
void hisi_dss_ovl_init(char __iomem *ovl_base, dss_ovl_t *s_ovl, int ovl_idx)
{
	int i = 0;

	if (NULL == ovl_base) {
		HISI_FB_ERR("ovl_base is NULL");
		return;
	}
	if (NULL == s_ovl) {
		HISI_FB_ERR("s_ovl is NULL");
		return;
	}

	memset(s_ovl, 0, sizeof(dss_ovl_t));

	s_ovl->ovl_size = inp32(ovl_base + OVL_SIZE);
	s_ovl->ovl_bg_color = inp32(ovl_base + OVL_BG_COLOR);
	s_ovl->ovl_dst_startpos = inp32(ovl_base + OVL_DST_STARTPOS);
	s_ovl->ovl_dst_endpos = inp32(ovl_base + OVL_DST_ENDPOS);
	s_ovl->ovl_gcfg = inp32(ovl_base + OVL_GCFG);

	if ((ovl_idx == DSS_OVL1) || (ovl_idx == DSS_OVL3)) {
		for (i = 0; i < OVL_2LAYER_NUM; i++) {
			s_ovl->ovl_layer[i].layer_pos =
				inp32(ovl_base + OVL_LAYER0_POS + i * 0x3C);
			s_ovl->ovl_layer[i].layer_size =
				inp32(ovl_base + OVL_LAYER0_SIZE + i * 0x3C);
			s_ovl->ovl_layer[i].layer_pattern =
				inp32(ovl_base + OVL_LAYER0_PATTERN + i * 0x3C);
			s_ovl->ovl_layer[i].layer_alpha =
				inp32(ovl_base + OVL_LAYER0_ALPHA + i * 0x3C);
			s_ovl->ovl_layer[i].layer_cfg =
				inp32(ovl_base + OVL_LAYER0_CFG + i * 0x3C);

			s_ovl->ovl_layer_pos[i].layer_pspos =
				inp32(ovl_base + OVL_LAYER0_PSPOS + i * 0x3C);
			s_ovl->ovl_layer_pos[i].layer_pepos =
				inp32(ovl_base + OVL_LAYER0_PEPOS + i * 0x3C);
		}

		s_ovl->ovl_block_size = inp32(ovl_base + OVL2_BLOCK_SIZE);
	} else {
		for (i = 0; i < OVL_6LAYER_NUM; i++) {
			s_ovl->ovl_layer[i].layer_pos =
				inp32(ovl_base + OVL_LAYER0_POS + i * 0x3C);
			s_ovl->ovl_layer[i].layer_size =
				inp32(ovl_base + OVL_LAYER0_SIZE + i * 0x3C);
			s_ovl->ovl_layer[i].layer_pattern =
				inp32(ovl_base + OVL_LAYER0_PATTERN + i * 0x3C);
			s_ovl->ovl_layer[i].layer_alpha =
				inp32(ovl_base + OVL_LAYER0_ALPHA + i * 0x3C);
			s_ovl->ovl_layer[i].layer_cfg =
				inp32(ovl_base + OVL_LAYER0_CFG + i * 0x3C);

			s_ovl->ovl_layer_pos[i].layer_pspos =
				inp32(ovl_base + OVL_LAYER0_PSPOS + i * 0x3C);
			s_ovl->ovl_layer_pos[i].layer_pepos =
				inp32(ovl_base + OVL_LAYER0_PEPOS + i * 0x3C);
		}

		s_ovl->ovl_block_size = inp32(ovl_base + OVL6_BLOCK_SIZE);
	}
}

void hisi_dss_ovl_set_reg(struct hisi_fb_data_type *hisifd,
	char __iomem *ovl_base, dss_ovl_t *s_ovl, int ovl_idx)
{
	int i = 0;

	if (hisifd == NULL) {
		HISI_FB_DEBUG("hisifd is NULL!\n");
		return;
	}

	if (ovl_base == NULL) {
		HISI_FB_DEBUG("ovl_base is NULL!\n");
		return;
	}

	if (s_ovl == NULL) {
		HISI_FB_DEBUG("s_ovl is NULL!\n");
		return;
	}

	if ((ovl_idx == DSS_OVL1) || (ovl_idx == DSS_OVL3)) {
		hisifd->set_reg(hisifd, ovl_base + OVL2_REG_DEFAULT, 0x1, 32, 0);
		hisifd->set_reg(hisifd, ovl_base + OVL2_REG_DEFAULT, 0x0, 32, 0);
	} else {
		hisifd->set_reg(hisifd, ovl_base + OVL6_REG_DEFAULT, 0x1, 32, 0);
		hisifd->set_reg(hisifd, ovl_base + OVL6_REG_DEFAULT, 0x0, 32, 0);
	}

	hisifd->set_reg(hisifd, ovl_base + OVL_SIZE, s_ovl->ovl_size, 32, 0);
	hisifd->set_reg(hisifd, ovl_base + OVL_BG_COLOR, s_ovl->ovl_bg_color, 32, 0);
	hisifd->set_reg(hisifd, ovl_base + OVL_DST_STARTPOS, s_ovl->ovl_dst_startpos, 32, 0);
	hisifd->set_reg(hisifd, ovl_base + OVL_DST_ENDPOS, s_ovl->ovl_dst_endpos, 32, 0);
	hisifd->set_reg(hisifd, ovl_base + OVL_GCFG, s_ovl->ovl_gcfg, 32, 0);

	if ((ovl_idx == DSS_OVL1) || (ovl_idx == DSS_OVL3)) {
		for (i = 0; i < OVL_2LAYER_NUM; i++) {
			if (s_ovl->ovl_layer_used[i] == 1) {
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_POS + i * 0x3C,
					s_ovl->ovl_layer[i].layer_pos, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_SIZE + i * 0x3C,
					s_ovl->ovl_layer[i].layer_size, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_PATTERN + i * 0x3C,
					s_ovl->ovl_layer[i].layer_pattern, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_ALPHA + i * 0x3C,
					s_ovl->ovl_layer[i].layer_alpha, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_CFG + i * 0x3C,
					s_ovl->ovl_layer[i].layer_cfg, 32, 0);

				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_PSPOS + i * 0x3C,
					s_ovl->ovl_layer_pos[i].layer_pspos, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_PEPOS + i * 0x3C,
					s_ovl->ovl_layer_pos[i].layer_pepos, 32, 0);
			} else {
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_POS + i * 0x3C,
					s_ovl->ovl_layer[i].layer_pos, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_SIZE + i * 0x3C,
					s_ovl->ovl_layer[i].layer_size, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_CFG + i * 0x3C,
					s_ovl->ovl_layer[i].layer_cfg, 32, 0);
			}
		}

		hisifd->set_reg(hisifd, ovl_base + OVL2_BLOCK_SIZE, s_ovl->ovl_block_size, 32, 0);
	} else {
		for (i = 0; i < OVL_6LAYER_NUM; i++) {
			if (s_ovl->ovl_layer_used[i] == 1) {
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_POS + i * 0x3C,
					s_ovl->ovl_layer[i].layer_pos, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_SIZE + i * 0x3C,
					s_ovl->ovl_layer[i].layer_size, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_PATTERN + i * 0x3C,
					s_ovl->ovl_layer[i].layer_pattern, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_ALPHA + i * 0x3C,
					s_ovl->ovl_layer[i].layer_alpha, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_CFG + i * 0x3C,
					s_ovl->ovl_layer[i].layer_cfg, 32, 0);

				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_PSPOS + i * 0x3C,
					s_ovl->ovl_layer_pos[i].layer_pspos, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_PEPOS + i * 0x3C,
					s_ovl->ovl_layer_pos[i].layer_pepos, 32, 0);
			} else {
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_POS + i * 0x3C,
					s_ovl->ovl_layer[i].layer_pos, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_SIZE + i * 0x3C,
					s_ovl->ovl_layer[i].layer_size, 32, 0);
				hisifd->set_reg(hisifd, ovl_base + OVL_LAYER0_CFG + i * 0x3C,
					s_ovl->ovl_layer[i].layer_cfg, 32, 0);
			}
		}

		hisifd->set_reg(hisifd, ovl_base + OVL6_BLOCK_SIZE, s_ovl->ovl_block_size, 32, 0);
	}
}
/*lint +e679 +e730 +e732*/

void hisi_dss_ov_set_reg_default_value(struct hisi_fb_data_type *hisifd,
	char __iomem *ovl_base, int ovl_idx)
{
	if (hisifd == NULL) {
		HISI_FB_DEBUG("hisifd is NULL!\n");
		return;
	}

	if (ovl_base == NULL) {
		HISI_FB_DEBUG("ovl_base is NULL!\n");
		return;
	}

	if ((ovl_idx == DSS_OVL1) || (ovl_idx == DSS_OVL3)) {
		hisifd->set_reg(hisifd, ovl_base + OVL2_REG_DEFAULT, 0x1, 32, 0);
		hisifd->set_reg(hisifd, ovl_base + OVL2_REG_DEFAULT, 0x0, 32, 0);
	} else {
		hisifd->set_reg(hisifd, ovl_base + OVL6_REG_DEFAULT, 0x1, 32, 0);
		hisifd->set_reg(hisifd, ovl_base + OVL6_REG_DEFAULT, 0x0, 32, 0);
	}
}

void hisi_dss_mctl_ov_set_ctl_dbg_reg(struct hisi_fb_data_type *hisifd, char __iomem *mctl_base, bool enable_cmdlist)
{
	if (hisifd == NULL) {
		HISI_FB_ERR("hisifd is null");
		return;
	}

	if (mctl_base == NULL) {
		HISI_FB_DEBUG("mctl_base is NULL!\n");
		return;
	}

	if (is_mipi_cmd_panel(hisifd) && (hisifd->ldi_data_gate_en == 1)) {
		//open underflow clear
		set_reg(mctl_base + MCTL_CTL_DBG, 0x782620, 32, 0);
	} else {
		//open underflow clear
		set_reg(mctl_base + MCTL_CTL_DBG, 0x78A620, 32, 0);
	}
}
/*lint -e715*/
void hisi_dss_post_clip_set_reg(struct hisi_fb_data_type *hisifd,
	char __iomem *post_clip_base, dss_post_clip_t *s_post_clip, int chn_idx)
{
	if (NULL == hisifd || NULL == post_clip_base || NULL == s_post_clip) {
		HISI_FB_ERR("NULL ptr.\n");
		return;
	}

	hisifd->set_reg(hisifd, post_clip_base + POST_CLIP_DISP_SIZE, s_post_clip->disp_size, 32, 0);
	hisifd->set_reg(hisifd, post_clip_base + POST_CLIP_CTL_HRZ, s_post_clip->clip_ctl_hrz, 32, 0);
	hisifd->set_reg(hisifd, post_clip_base + POST_CLIP_CTL_VRZ, s_post_clip->clip_ctl_vrz, 32, 0);
	hisifd->set_reg(hisifd, post_clip_base + POST_CLIP_EN, s_post_clip->ctl_clip_en, 32, 0);
}
/*lint +e715*/
uint32_t hisi_dss_mif_get_invalid_sel(dss_img_t *img, uint32_t transform, int v_scaling_factor,
	uint8_t is_tile, bool rdma_stretch_enable)
{
	uint32_t invalid_sel_val = 0;
	uint32_t tlb_tag_org = 0;

	if (img == NULL) {
		HISI_FB_ERR("img is null");
		return 0;
	}

	if ((transform == (HISI_FB_TRANSFORM_ROT_90 | HISI_FB_TRANSFORM_FLIP_H))
		|| (transform == (HISI_FB_TRANSFORM_ROT_90 | HISI_FB_TRANSFORM_FLIP_V))) {
		transform = HISI_FB_TRANSFORM_ROT_90;
	}

	tlb_tag_org =  (transform & 0x7) |
		((is_tile ? 1 : 0) << 3) | ((rdma_stretch_enable ? 1 : 0) << 4);

	switch (tlb_tag_org) {
	case MMU_TLB_TAG_ORG_0x0:
		invalid_sel_val = 1;
		break;
	case MMU_TLB_TAG_ORG_0x1:
		invalid_sel_val = 1;
		break;
	case MMU_TLB_TAG_ORG_0x2:
		invalid_sel_val = 2;
		break;
	case MMU_TLB_TAG_ORG_0x3:
		invalid_sel_val = 2;
		break;
	case MMU_TLB_TAG_ORG_0x4:
		invalid_sel_val = 0;
		break;
	case MMU_TLB_TAG_ORG_0x7:
		invalid_sel_val = 0;
		break;

	case MMU_TLB_TAG_ORG_0x8:
		invalid_sel_val = 3;
		break;
	case MMU_TLB_TAG_ORG_0x9:
		invalid_sel_val = 3;
		break;
	case MMU_TLB_TAG_ORG_0xA:
		invalid_sel_val = 3;
		break;
	case MMU_TLB_TAG_ORG_0xB:
		invalid_sel_val = 3;
		break;
	case MMU_TLB_TAG_ORG_0xC:
		invalid_sel_val = 0;
		break;
	case MMU_TLB_TAG_ORG_0xF:
		invalid_sel_val = 0;
		break;

	case MMU_TLB_TAG_ORG_0x10:
		invalid_sel_val = 1;
		break;
	case MMU_TLB_TAG_ORG_0x11:
		invalid_sel_val = 1;
		break;
	case MMU_TLB_TAG_ORG_0x12:
		invalid_sel_val = 2;
		break;
	case MMU_TLB_TAG_ORG_0x13:
		invalid_sel_val = 2;
		break;
	case MMU_TLB_TAG_ORG_0x14:
		invalid_sel_val = 0;
		break;
	case MMU_TLB_TAG_ORG_0x17:
		invalid_sel_val = 0;
		break;

	case MMU_TLB_TAG_ORG_0x18:
		invalid_sel_val = 3;
		break;
	case MMU_TLB_TAG_ORG_0x19:
		invalid_sel_val = 3;
		break;
	case MMU_TLB_TAG_ORG_0x1A:
		invalid_sel_val = 3;
		break;
	case MMU_TLB_TAG_ORG_0x1B:
		invalid_sel_val = 3;
		break;
	case MMU_TLB_TAG_ORG_0x1C:
		invalid_sel_val = 0;
		break;
	case MMU_TLB_TAG_ORG_0x1F:
		invalid_sel_val = 0;
		break;

	default:
		invalid_sel_val = 0;
		HISI_FB_ERR("not support this tlb_tag_org(0x%x)!\n", tlb_tag_org);
		break;
	}

	return invalid_sel_val;
}

int hisi_dss_check_userdata(struct hisi_fb_data_type *hisifd,
	dss_overlay_t *pov_req, dss_overlay_block_t *pov_h_block_infos)
{
	int i = 0;
	dss_wb_layer_t *wb_layer = NULL;

	if (hisifd == NULL) {
		HISI_FB_ERR("invalid hisifd!");
		return -EINVAL;
	}

	if (pov_req == NULL) {
		HISI_FB_ERR("fb%d, invalid pov_req!", hisifd->index);
		return -EINVAL;
	}

	if (pov_h_block_infos == NULL) {
		HISI_FB_ERR("fb%d, invalid pov_h_block_infos!", hisifd->index);
		return -EINVAL;
	}

	if ((pov_req->ov_block_nums <= 0) ||
		(pov_req->ov_block_nums > HISI_DSS_OV_BLOCK_NUMS)) {
		HISI_FB_ERR("fb%d, invalid ov_block_nums=%d!",
			hisifd->index, pov_req->ov_block_nums);
		return -EINVAL;
	}

	if ((pov_h_block_infos->layer_nums <= 0)
		|| (pov_h_block_infos->layer_nums > OVL_LAYER_NUM_MAX)) {
		HISI_FB_ERR("fb%d, invalid layer_nums=%d!",
			hisifd->index, pov_h_block_infos->layer_nums);
		return -EINVAL;
	}

	if ((pov_req->ovl_idx < 0) ||
		pov_req->ovl_idx >= DSS_OVL_IDX_MAX) {
		HISI_FB_ERR("fb%d, invalid ovl_idx=%d!",
			hisifd->index, pov_req->ovl_idx);
		return -EINVAL;
	}

	if (hisifd->index == PRIMARY_PANEL_IDX) {
		if (hisifd->panel_info.dirty_region_updt_support) {
			if (pov_req->dirty_rect.x < 0 || pov_req->dirty_rect.y < 0 ||
				pov_req->dirty_rect.w < 0 || pov_req->dirty_rect.h < 0) {
				HISI_FB_ERR("dirty_rect(%d, %d, %d, %d) is out of range!\n",
					pov_req->dirty_rect.x, pov_req->dirty_rect.y,
					pov_req->dirty_rect.w, pov_req->dirty_rect.h);
				return -EINVAL;
			}
		}
	}

	if (hisifd->index == AUXILIARY_PANEL_IDX) {
		if (pov_req->wb_enable != 1) {
			HISI_FB_ERR("pov_req->wb_enable=%u is invalid!\n", pov_req->wb_enable);
			return -EINVAL;
		}

		if ((pov_req->wb_layer_nums <= 0) ||
			(pov_req->wb_layer_nums > MAX_DSS_DST_NUM)) {
			HISI_FB_ERR("fb%d, invalid wb_layer_nums=%d!",
				hisifd->index, pov_req->wb_layer_nums);
			return -EINVAL;
		}

		if (pov_req->wb_ov_rect.x < 0 || pov_req->wb_ov_rect.y < 0) {
			HISI_FB_ERR("wb_ov_rect(%d, %d) is out of range!\n",
				pov_req->wb_ov_rect.x, pov_req->wb_ov_rect.y);
			return -EINVAL;
		}

		if (pov_req->wb_compose_type >= DSS_WB_COMPOSE_TYPE_MAX) {
			HISI_FB_ERR("wb_compose_type=%u is invalid!\n", pov_req->wb_compose_type);
			return -EINVAL;
		}

		for (i = 0; i < pov_req->wb_layer_nums; i++) {
			wb_layer = &(pov_req->wb_layer_infos[i]);

			if (wb_layer->chn_idx < DSS_WCHN_W0 || wb_layer->chn_idx > DSS_WCHN_W1) {
				HISI_FB_ERR("fb%d, wchn_idx=%d is invalid!", hisifd->index, wb_layer->chn_idx);
				return -EINVAL;
			}

			if (wb_layer->dst.format >= HISI_FB_PIXEL_FORMAT_MAX) {
				HISI_FB_ERR("fb%d, format=%d is invalid!", hisifd->index, wb_layer->dst.format);
				return -EINVAL;
			}

			if ((wb_layer->dst.bpp == 0) || (wb_layer->dst.width == 0) || (wb_layer->dst.height == 0)
				||(wb_layer->dst.stride == 0)) {
				HISI_FB_ERR("fb%d, bpp=%d, width=%d, height=%d, stride=%d is invalid!",
					hisifd->index, wb_layer->dst.bpp, wb_layer->dst.width, wb_layer->dst.height,
					wb_layer->dst.stride);
				return -EINVAL;
			}


			if (wb_layer->need_cap & CAP_AFBCE) {
				if ((wb_layer->dst.afbc_header_stride == 0) || (wb_layer->dst.afbc_payload_stride == 0)) {
					HISI_FB_ERR("fb%d, afbc_header_stride=%d, afbc_payload_stride=%d is invalid!",
						hisifd->index, wb_layer->dst.afbc_header_stride, wb_layer->dst.afbc_payload_stride);
					return -EINVAL;
				}
			}

			if (wb_layer->dst.csc_mode >= DSS_CSC_MOD_MAX) {
				HISI_FB_ERR("fb%d, csc_mode=%d is invalid!", hisifd->index, wb_layer->dst.csc_mode);
				return -EINVAL;
			}

			if (wb_layer->dst.afbc_scramble_mode >= DSS_AFBC_SCRAMBLE_MODE_MAX) {
				HISI_FB_ERR("fb%d, afbc_scramble_mode=%d is invalid!", hisifd->index, wb_layer->dst.afbc_scramble_mode);
				return -EINVAL;
			}

			if (wb_layer->src_rect.x < 0 || wb_layer->src_rect.y < 0 ||
				wb_layer->src_rect.w <= 0 || wb_layer->src_rect.h <= 0) {
				HISI_FB_ERR("src_rect(%d, %d, %d, %d) is out of range!\n",
					wb_layer->src_rect.x, wb_layer->src_rect.y,
					wb_layer->src_rect.w, wb_layer->src_rect.h);
				return -EINVAL;
			}

			if (wb_layer->dst_rect.x < 0 || wb_layer->dst_rect.y < 0 ||
				wb_layer->dst_rect.w <= 0 || wb_layer->dst_rect.h <= 0) {
				HISI_FB_ERR("dst_rect(%d, %d, %d, %d) is out of range!\n",
					wb_layer->dst_rect.x, wb_layer->dst_rect.y,
					wb_layer->dst_rect.w, wb_layer->dst_rect.h);
				return -EINVAL;
			}
		}
	}

	return 0;
}

int hisi_dss_check_layer_par(struct hisi_fb_data_type *hisifd, dss_layer_t *layer)
{
	if (hisifd == NULL) {
		HISI_FB_ERR("hisifd is NULL, return!");
		return -EINVAL;
	}

	if (layer == NULL) {
		HISI_FB_ERR("layer is NULL, return!");
		return -EINVAL;
	}

	if (layer->layer_idx < 0 || layer->layer_idx >= OVL_LAYER_NUM_MAX) {
		HISI_FB_ERR("fb%d, layer_idx=%d is invalid!", hisifd->index, layer->layer_idx);
		return -EINVAL;
	}

	if (layer->chn_idx < 0 || layer->chn_idx >= DSS_WCHN_W0) {
		HISI_FB_ERR("fb%d, rchn_idx=%d is invalid!", hisifd->index, layer->chn_idx);
		return -EINVAL;
	}

	if ((layer->layer_idx != 0) && (layer->need_cap & CAP_BASE)) {
		HISI_FB_ERR("fb%d, layer%d is not base!", hisifd->index, layer->layer_idx);
		return -EINVAL;
	}

	if (layer->need_cap & (CAP_BASE | CAP_DIM | CAP_PURE_COLOR))
		return 0;

	if (hisifd->index == AUXILIARY_PANEL_IDX) {
		if (layer->chn_idx == DSS_RCHN_D2) {
			HISI_FB_ERR("fb%d, chn_idx[%d] does not used by offline play!", hisifd->index, layer->chn_idx);
			return -EINVAL;
		}
	}

	if (layer->chn_idx < 0 || layer->chn_idx >= DSS_WCHN_W0) {
		HISI_FB_ERR("fb%d, rchn_idx=%d is invalid!", hisifd->index, layer->chn_idx);
		return -EINVAL;
	}

	if (layer->blending < 0 || layer->blending >= HISI_FB_BLENDING_MAX) {
		HISI_FB_ERR("fb%d, blending=%d is invalid!", hisifd->index, layer->blending);
		return -EINVAL;
	}

	if (layer->img.format >= HISI_FB_PIXEL_FORMAT_MAX) {
		HISI_FB_ERR("fb%d, format=%d is invalid!", hisifd->index, layer->img.format);
		return -EINVAL;
	}

	if ((layer->img.bpp == 0) || (layer->img.width == 0) || (layer->img.height == 0)
		||(layer->img.stride == 0)) {
		HISI_FB_ERR("fb%d, bpp=%d, width=%d, height=%d, stride=%d is invalid!",
			hisifd->index, layer->img.bpp, layer->img.width, layer->img.height,
			layer->img.stride);
		return -EINVAL;
	}


	if (layer->need_cap & CAP_AFBCD) {
		if ((layer->img.afbc_header_stride == 0) || (layer->img.afbc_payload_stride == 0)
			|| (layer->img.mmbuf_size == 0)) {
			HISI_FB_ERR("fb%d, afbc_header_stride=%d, afbc_payload_stride=%d, mmbuf_size=%d is invalid!",
				hisifd->index, layer->img.afbc_header_stride,
				layer->img.afbc_payload_stride, layer->img.mmbuf_size);
			return -EINVAL;
		}
	}

	if (layer->img.csc_mode >= DSS_CSC_MOD_MAX) {
		HISI_FB_ERR("fb%d, csc_mode=%d is invalid!", hisifd->index, layer->img.csc_mode);
		return -EINVAL;
	}

	if (layer->img.afbc_scramble_mode >= DSS_AFBC_SCRAMBLE_MODE_MAX) {
		HISI_FB_ERR("fb%d, afbc_scramble_mode=%d is invalid!", hisifd->index, layer->img.afbc_scramble_mode);
		return -EINVAL;
	}

	if (layer->src_rect.x < 0 || layer->src_rect.y < 0 ||
		layer->src_rect.w <= 0 || layer->src_rect.h <= 0) {
		HISI_FB_ERR("src_rect(%d, %d, %d, %d) is out of range!\n",
			layer->src_rect.x, layer->src_rect.y,
			layer->src_rect.w, layer->src_rect.h);
		return -EINVAL;
	}

	if (layer->src_rect_mask.x < 0 || layer->src_rect_mask.y < 0 ||
		layer->src_rect_mask.w < 0 || layer->src_rect_mask.h < 0) {
		HISI_FB_ERR("src_rect_mask(%d, %d, %d, %d) is out of range!\n",
			layer->src_rect_mask.x, layer->src_rect_mask.y,
			layer->src_rect_mask.w, layer->src_rect_mask.h);
		return -EINVAL;
	}

	if (layer->dst_rect.x < 0 || layer->dst_rect.y < 0 ||
		layer->dst_rect.w <= 0 || layer->dst_rect.h <= 0) {
		HISI_FB_ERR("dst_rect(%d, %d, %d, %d) is out of range!\n",
			layer->dst_rect.x, layer->dst_rect.y,
			layer->dst_rect.w, layer->dst_rect.h);
		return -EINVAL;
	}

	return 0;
}

void hisifb_dss_disreset(struct hisi_fb_data_type *hisifd)
{
}

void hisi_dss_mctl_sys_init(char __iomem *mctl_sys_base, dss_mctl_sys_t *s_mctl_sys)
{
	int i;

	if (NULL == mctl_sys_base || NULL == s_mctl_sys) {
		HISI_FB_ERR("NULL ptr.\n");
		return;
	}
	memset(s_mctl_sys, 0, sizeof(dss_mctl_sys_t));

	for (i= 0; i < DSS_OVL_IDX_MAX; i++) {
		s_mctl_sys->chn_ov_sel[i] = inp32(mctl_sys_base + MCTL_RCH_OV0_SEL + i * 0x4);//lint !e732
	}

	for (i= 0; i < DSS_WCH_MAX; i++) {
		s_mctl_sys->wchn_ov_sel[i] = inp32(mctl_sys_base + MCTL_WCH_OV2_SEL + i * 0x4);//lint !e732
	}
}

