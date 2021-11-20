#! /bin/bash
#
gcc -c -Wall -fopenmp functions_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp functions_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm functions_openmp.o
mv a.out $HOME/binc/functions_openmp
#
echo "Normal end of execution."
