#! /bin/bash
#
cp blas1_c.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include blas1_c.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas1_c.o ~/libc/blas1_c.o
#
echo "Normal end of execution."
