#! /bin/bash
#
cp triangle_interpolate.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include triangle_interpolate.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_interpolate.o ~/libc/triangle_interpolate.o
#
echo "Normal end of execution."
