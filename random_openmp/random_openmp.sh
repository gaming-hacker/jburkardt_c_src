#! /bin/bash
#
gcc -c -Wall -fopenmp random_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp random_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm random_openmp.o
mv a.out $HOME/binc/random_openmp
#
echo "Normal end of execution."
