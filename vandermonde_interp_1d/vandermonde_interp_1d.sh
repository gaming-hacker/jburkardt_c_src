#! /bin/bash
#
cp vandermonde_interp_1d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include vandermonde_interp_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv vandermonde_interp_1d.o ~/libc/vandermonde_interp_1d.o
#
echo "Normal end of execution."
