#! /bin/bash
#
cp fem2d_bvp_linear.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fem2d_bvp_linear.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem2d_bvp_linear.o ~/libc/fem2d_bvp_linear.o
#
echo "Normal end of execution."
