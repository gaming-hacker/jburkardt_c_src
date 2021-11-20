#! /bin/bash
#
cp fem1d_bvp_quadratic.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fem1d_bvp_quadratic.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem1d_bvp_quadratic.o ~/libc/fem1d_bvp_quadratic.o
#
echo "Normal end of execution."
