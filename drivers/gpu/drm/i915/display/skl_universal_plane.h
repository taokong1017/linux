/* SPDX-License-Identifier: MIT */
/*
 * Copyright © 2020 Intel Corporation
 */

#ifndef _SKL_UNIVERSAL_PLANE_H_
#define _SKL_UNIVERSAL_PLANE_H_

#include <linux/types.h>

struct intel_crtc;
struct intel_display;
struct intel_initial_plane_config;
struct intel_plane_state;
struct skl_ddb_entry;
struct skl_wm_level;

enum pipe;
enum plane_id;

struct intel_plane *
skl_universal_plane_create(struct intel_display *display,
			   enum pipe pipe, enum plane_id plane_id);

void skl_get_initial_plane_config(struct intel_crtc *crtc,
				  struct intel_initial_plane_config *plane_config);
bool skl_fixup_initial_plane_config(struct intel_crtc *crtc,
				    const struct intel_initial_plane_config *plane_config);

int skl_format_to_fourcc(int format, bool rgb_order, bool alpha);

int skl_calc_main_surface_offset(const struct intel_plane_state *plane_state,
				 int *x, int *y, u32 *offset);

void icl_link_nv12_planes(struct intel_plane_state *uv_plane_state,
			  struct intel_plane_state *y_plane_state);

bool icl_is_nv12_y_plane(struct intel_display *display,
			 enum plane_id plane_id);
u8 icl_hdr_plane_mask(void);
bool icl_is_hdr_plane(struct intel_display *display, enum plane_id plane_id);

u32 skl_plane_aux_dist(const struct intel_plane_state *plane_state,
		       int color_plane);

#endif
