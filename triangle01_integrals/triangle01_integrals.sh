#!/bin/bash
#
cp triangle01_integrals.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle01_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle01_integrals.o ~/libc/triangle01_integrals.o
#
echo "Normal end of execution."
