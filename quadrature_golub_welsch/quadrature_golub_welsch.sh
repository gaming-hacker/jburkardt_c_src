#! /bin/bash
#
cp quadrature_golub_welsch.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include quadrature_golub_welsch.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrature_golub_welsch.o ~/libc/quadrature_golub_welsch.o
#
echo "Normal end of execution."
