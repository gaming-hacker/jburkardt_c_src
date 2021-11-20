#! /bin/bash
#
gcc -c -Wall -fopenmp quad_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp quad_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quad_openmp.o
mv a.out $HOME/binc/quad_openmp
#
echo "Normal end of execution."
