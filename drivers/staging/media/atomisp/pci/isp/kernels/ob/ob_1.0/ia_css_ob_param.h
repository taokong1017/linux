/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Support for Intel Camera Imaging ISP subsystem.
 * Copyright (c) 2015, Intel Corporation.
 */

#ifndef __IA_CSS_OB_PARAM_H
#define __IA_CSS_OB_PARAM_H

#include "type_support.h"
#include "vmem.h"

#define OBAREA_MASK_SIZE 64
#define OBAREA_LENGTHBQ_INVERSE_SHIFT     12

/* AREA_LENGTH_UNIT is dependent on NWAY, requires rewrite */
#define AREA_LENGTH_UNIT BIT(12)

/* OB (Optical Black) */
struct sh_css_isp_ob_stream_config {
	unsigned int isp_pipe_version;
	unsigned int raw_bit_depth;
};

struct sh_css_isp_ob_params {
	s32 blacklevel_gr;
	s32 blacklevel_r;
	s32 blacklevel_b;
	s32 blacklevel_gb;
	s32 area_start_bq;
	s32 area_length_bq;
	s32 area_length_bq_inverse;
};

struct sh_css_isp_ob_vmem_params {
	VMEM_ARRAY(vmask, OBAREA_MASK_SIZE);
};

#endif /* __IA_CSS_OB_PARAM_H */
