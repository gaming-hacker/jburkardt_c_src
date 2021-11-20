#! /bin/bash
#
gcc -c -Wall -fopenmp quad2d_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp quad2d_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quad2d_openmp.o
mv a.out $HOME/binc/quad2d_openmp
#
echo "Normal end of execution."
