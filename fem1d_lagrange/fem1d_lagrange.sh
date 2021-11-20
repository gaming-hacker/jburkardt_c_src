#! /bin/bash
#
cp fem1d_lagrange.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include fem1d_lagrange.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem1d_lagrange.o ~/libc/fem1d_lagrange.o
#
echo "Normal end of execution."
