#! /bin/bash
#
gcc -c -Wall -fopenmp julia_set_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp julia_set_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm julia_set_openmp.o
mv a.out $HOME/binc/julia_set_openmp
#
echo "Normal end of execution."
