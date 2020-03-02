# Copyright 2017-2018 NXP

#IMX_MKIMAGE_SRC ?= "git://source.codeaurora.org/external/imx/imx-mkimage.git;protocol=https"
#SRCBRANCH = "imx_4.14.98_2.0.0_ga"
#SRC_URI = "${IMX_MKIMAGE_SRC};branch=${SRCBRANCH}"
#SRCREV = "dd0234001713623c79be92b60fa88bc07b07f24f"
SRC_URI = "file://imx-boot.tar.xz"


DEPENDS = "zlib-native openssl-native"
