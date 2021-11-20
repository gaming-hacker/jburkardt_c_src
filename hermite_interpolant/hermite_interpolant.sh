#! /bin/bash
#
cp hermite_interpolant.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hermite_interpolant.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_interpolant.o ~/libc/hermite_interpolant.o
#
echo "Normal end of execution."
