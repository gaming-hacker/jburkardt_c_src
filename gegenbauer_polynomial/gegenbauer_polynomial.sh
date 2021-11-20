#! /bin/bash
#
cp gegenbauer_polynomial.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include gegenbauer_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv gegenbauer_polynomial.o ~/libc/gegenbauer_polynomial.o
#
echo "Normal end of execution."
