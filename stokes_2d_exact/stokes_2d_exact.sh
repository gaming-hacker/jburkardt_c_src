#! /bin/bash
#
cp stokes_2d_exact.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include stokes_2d_exact.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stokes_2d_exact.o ~/libc/stokes_2d_exact.o
#
echo "Normal end of execution."
