# AnyKernel2 Ramdisk Mod Script
# osm0sis @ xda-developers

## AnyKernel setup
# begin properties
properties() {
kernel.string=foe.kernel @ XDA
do.devicecheck=0
do.modules=0
do.cleanup=1
do.cleanuponabort=1
device.name1=
device.name2=
} # end properties

## AnyKernel methods (DO NOT CHANGE)
# import patching functions/variables - see for reference
. /tmp/anykernel/tools/ak2-core.sh;
          
ui_print "***********************************************";
ui_print "                        ";
ui_print "                 _____               ";
ui_print "               _/ ____\____   ____   ";
ui_print "               \   __\/  _ \_/ __ \  ";
ui_print "                |  | (  <_> )  ___/  ";
ui_print "                |__|  \____/ \___  > ";
ui_print "                                 \/  ";
ui_print "                                       ";
ui_print "***********************************************";
ui_print "                        ";
ui_print "                        ";
ui_print "                        ";
ui_print "              foe.kernel      ";
ui_print "                  by          ";
ui_print "            fanthagiro foe ";
ui_print "                        ";
ui_print "                        ";


# shell variables
block=/dev/block/bootdevice/by-name/kernel;
ramdisk_compression=auto;

# reset for kernel patching
reset_ak;
mv /tmp/anykernel/kernel-Image.gz /tmp/anykernel/Image.gz;


## AnyKernel kernel install

split_boot;

flash_boot;

## end install
