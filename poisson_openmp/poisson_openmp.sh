#! /bin/bash
#
gcc -c -Wall -fopenmp poisson_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp poisson_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm poisson_openmp.o
mv a.out $HOME/binc/poisson_openmp
#
#
echo "Normal end of execution."
