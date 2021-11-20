#! /bin/bash
#
cp quadrature_weights_vandermonde.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include quadrature_weights_vandermonde.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrature_weights_vandermonde.o ~/libc/quadrature_weights_vandermonde.o
#
echo "Normal end of execution."
