#! /bin/bash
#
cp navier_stokes_3d_exact.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include navier_stokes_3d_exact.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv navier_stokes_3d_exact.o ~/libc/navier_stokes_3d_exact.o
#
echo "Normal end of execution."
