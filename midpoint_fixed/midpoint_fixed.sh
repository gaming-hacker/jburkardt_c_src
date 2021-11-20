#! /bin/bash
#
cp midpoint_fixed.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include midpoint_fixed.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv midpoint_fixed.o ~/libc/midpoint_fixed.o
#
echo "Normal end of execution."
