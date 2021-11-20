#! /bin/bash
#
cp fem2d_bvp_serene.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fem2d_bvp_serene.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem2d_bvp_serene.o ~/libc/fem2d_bvp_serene.o
#
echo "Normal end of execution."
