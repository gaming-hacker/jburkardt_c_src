#! /bin/bash
#
cp blas1_z.h /$HOME/include
#
gcc -c -Wall -I$HOME/include blas1_z.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas1_z.o ~/libc/blas1_z.o
#
echo "Normal end of execution."
