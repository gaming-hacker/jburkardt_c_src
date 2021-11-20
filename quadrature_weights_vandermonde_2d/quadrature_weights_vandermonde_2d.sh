#! /bin/bash
#
cp quadrature_weights_vandermonde_2d.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include quadrature_weights_vandermonde_2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrature_weights_vandermonde_2d.o ~/libc/quadrature_weights_vandermonde_2d.o
#
echo "Normal end of execution."
