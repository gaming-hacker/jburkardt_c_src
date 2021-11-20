#! /bin/bash
#
cp quadrature_least_squares.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include quadrature_least_squares.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrature_least_squares.o ~/libc/quadrature_least_squares.o
#
echo "Normal end of execution."
