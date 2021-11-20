#! /bin/bash
#
gcc -c -Wall -fopenmp prime_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp prime_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm prime_openmp.o
mv a.out $HOME/binc/prime_openmp
#
echo "Normal end of execution."
