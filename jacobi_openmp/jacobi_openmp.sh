#! /bin/bash
#
gcc -c -Wall -fopenmp jacobi_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp -o jacobi_openmp jacobi_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm jacobi_openmp.o
#
mv jacobi_openmp $HOME/binc/jacobi_openmp
#
echo "Normal end of execution."
