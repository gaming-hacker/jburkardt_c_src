#! /bin/bash
#
gcc -c -Wall -fopenmp multitask_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp multitask_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm multitask_openmp.o
mv a.out $HOME/binc/multitask_openmp
#
echo "Normal end of execution."
