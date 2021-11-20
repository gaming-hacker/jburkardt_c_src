#! /bin/bash
#
cp chebyshev_polynomial.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include chebyshev_polynomial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chebyshev_polynomial.o ~/libc/chebyshev_polynomial.o
#
echo "Normal end of execution."
