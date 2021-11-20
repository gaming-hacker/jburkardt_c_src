#! /bin/bash
#
cp barycentric_interp_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include barycentric_interp_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv barycentric_interp_1d.o ~/libc/barycentric_interp_1d.o
#
echo "Normal end of execution."
