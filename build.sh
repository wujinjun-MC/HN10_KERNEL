#!/bin/bash
export PATH=$PATH:/work/HN10_KERNEL/HN10_KERNEL/android-ndk-master/toolchains/aarch64-linux-android-4.9/prebuilt/linux-x86_64/bin
export CROSS_COMPILE=aarch64-linux-android-
mkdir out
make ARCH=arm64 O=out radioactive_defconfig
make ARCH=arm64 O=out -j5

