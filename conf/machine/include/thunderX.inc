# Cavium Thunderx Soc

SOC_FAMILY = "thunderX"
include conf/machine/include/soc-family.inc

require conf/machine/include/tune-thunderx.inc

MACHINE_EXTRA_RRECOMMENDS ?= " kernel-modules"
SERIAL_CONSOLES = "115200;ttyAMA0"

#u-boot
KERNEL_EXTRA_ARGS = 'LOADADDR=0x080080000'

PREFERRED_PROVIDER_virtual/kernel ?= "linux-stable"
PREFERRED_VERSION_linux-stable ?= "4.2%"
KERNEL_IMAGETYPE = "uImage"
IMAGE_FSTYPES = " ext4 cpio.gz tar.gz"

MACHINE_EXTRA_RRECOMMENDS ?= " kernel-modules"
MACHINE_FEATURES_append = "pci ext2 serial usbhost vfat"
