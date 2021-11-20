#! /bin/bash
#
cp hypersphere_properties.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include hypersphere_properties.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypersphere_properties.o ~/libc/hypersphere_properties.o
#
echo "Normal end of execution."
