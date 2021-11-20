#! /bin/bash
#
cp lagrange_interp_1d.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include lagrange_interp_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lagrange_interp_1d.o ~/libc/lagrange_interp_1d.o
#
echo "Normal end of execution."
