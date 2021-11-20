#! /bin/bash
#
cp lobatto_polynomial.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include lobatto_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lobatto_polynomial.o ~/libc/lobatto_polynomial.o
#
echo "Normal end of execution."
