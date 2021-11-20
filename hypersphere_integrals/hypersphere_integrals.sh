#! /bin/bash
#
cp hypersphere_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hypersphere_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypersphere_integrals.o ~/libc/hypersphere_integrals.o
#
echo "Normal end of execution."
