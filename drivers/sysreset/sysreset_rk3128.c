/*
 * (C) Copyright 2015 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <errno.h>
#include <sysreset.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/cru_rk3128.h>
#include <asm/arch/hardware.h>
#include <linux/err.h>

int rk3128_sysreset_request(struct udevice *dev, enum sysreset_t type)
{
	struct rk3128_cru *cru = rockchip_get_cru();

	if (IS_ERR(cru))
		return PTR_ERR(cru);
	switch (type) {
	case SYSRESET_WARM:
		writel(0xeca8, &cru->cru_glb_srst_snd_value);
		break;
	case SYSRESET_COLD:
		writel(0xfdb9, &cru->cru_glb_srst_fst_value);
		break;
	default:
		return -EPROTONOSUPPORT;
	}

	return -EINPROGRESS;
}

static struct sysreset_ops rk3128_sysreset = {
	.request	= rk3128_sysreset_request,
};

U_BOOT_DRIVER(sysreset_rk3128) = {
	.name	= "rk3128_sysreset",
	.id	= UCLASS_SYSRESET,
	.ops	= &rk3128_sysreset,
};
