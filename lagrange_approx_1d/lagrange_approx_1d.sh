#! /bin/bash
#
cp lagrange_approx_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include lagrange_approx_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lagrange_approx_1d.o ~/libc/lagrange_approx_1d.o
#
echo "Normal end of execution."
