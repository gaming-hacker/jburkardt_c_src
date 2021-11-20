#! /bin/bash
#
cp laguerre_polynomial.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include laguerre_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv laguerre_polynomial.o ~/libc/laguerre_polynomial.o
#
echo "Normal end of execution."
