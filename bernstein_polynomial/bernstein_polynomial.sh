#! /bin/bash
#
cp bernstein_polynomial.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include bernstein_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bernstein_polynomial.o ~/libc/bernstein_polynomial.o
#
echo "Normal end of execution."
