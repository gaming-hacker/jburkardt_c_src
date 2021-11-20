#! /bin/bash
#
cp blas1_d.h /$HOME/include
#
gcc -c -Wall -I$HOME/include blas1_d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas1_d.o ~/libc/blas1_d.o
#
echo "Normal end of execution."
