#! /bin/bash
#
cp hermite_polynomial.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hermite_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_polynomial.o ~/libc/hermite_polynomial.o
#
echo "Normal end of execution."
