SECTION = "kernel"
DESCRIPTION = "Linux kernel for Octeon devices"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

inherit kernel
require recipes-kernel/linux/linux-yocto.inc

# Look in the generic major.minor directory for files
FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-4.2:"

S = "${WORKDIR}/git"

KBRANCH_cn88xx-evb ?= "linux-4.2.y"
KBRANCH_cn88xxbe-evb ?= "linux-4.2.y"

SRCREV_machine_cn88xx-evb ?= "f4ca8c1b9c4e24a693794badf09d3a8857c46a80"
SRCREV_machine_cn88xxbe-evb ?= "f4ca8c1b9c4e24a693794badf09d3a8857c46a80"

PV = "4.2.1+git${SRCPV}"

SRC_URI = "git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git;branch=${KBRANCH};name=machine"

SRC_URI += "file://defconfig"

SRC_URI += "file://0001-arm64-Add-uImage-target.patch \
            file://0001-Add-uinstall-for-arm64.patch \
            file://0001-add-uinstall-to-Mafile.patch \
        "

KCONF_BSP_AUDIT_LEVEL = "0"
COMPATIBLE_MACHINE_cn88xx-evb = "cn88xx-evb"
COMPATIBLE_MACHINE_cn88xxbe-evb = "cn88xxbe-evb"
