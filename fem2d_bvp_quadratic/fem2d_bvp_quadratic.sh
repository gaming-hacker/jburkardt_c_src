#! /bin/bash
#
cp fem2d_bvp_quadratic.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fem2d_bvp_quadratic.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem2d_bvp_quadratic.o ~/libc/fem2d_bvp_quadratic.o
#
echo "Normal end of execution."
