require conf/machine/include/arm/arch-armv8.inc

DEFAULTTUNE ?= "thunderX"
AVAILTUNES += "thunderX thunderX_be"

TUNEVALID[thunderX] = "Enable instructions for Cavium ThunderX"

TUNE_CCARGS .= "${@bb.utils.contains("TUNE_FEATURES", "thunderX", " -mcpu=thunderx ", "",d)}"

ARMPKGARCH_tune-thunderX ?= "thunderX"
ARMPKGARCH_tune-thunderX_be ?= "thunderX_be"

TUNE_FEATURES_tune-thunderX ?= "${TUNE_FEATURES_tune-aarch64} thunderX"
TUNE_FEATURES_tune-thunderX_be ?= "${TUNE_FEATURES_tune-thunderX} bigendian"
BASE_LIB_tune-thunderX = "lib64"
BASE_LIB_tune-thunderX_be = "lib64"

PACKAGE_EXTRA_ARCHS_tune-thunderX = "aarch64 thunderX"
PACKAGE_EXTRA_ARCHS_tune-thunderX_be = "aarch64_be thunderX_be"
