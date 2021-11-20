#! /bin/bash
#
cp lagrange_interp_nd.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include lagrange_interp_nd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lagrange_interp_nd.o ~/libc/lagrange_interp_nd.o
#
echo "Normal end of execution."
