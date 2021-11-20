#! /bin/bash
#
cp vandermonde.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include vandermonde.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv vandermonde.o ~/libc/vandermonde.o
#
echo "Normal end of execution."
