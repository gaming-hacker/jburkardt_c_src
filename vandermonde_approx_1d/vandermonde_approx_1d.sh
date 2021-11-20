#! /bin/bash
#
cp vandermonde_approx_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include vandermonde_approx_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv vandermonde_approx_1d.o ~/libc/vandermonde_approx_1d.o
#
echo "Normal end of execution."
