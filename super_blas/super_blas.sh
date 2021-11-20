#! /bin/bash
#
cp super_blas.h /$HOME/include
#
gcc -c -Wall super_blas.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv super_blas.o ~/libc/super_blas.o
#
echo "Normal end of execution."
