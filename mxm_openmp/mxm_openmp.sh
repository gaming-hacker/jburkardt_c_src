#! /bin/bash
#
gcc -c -Wall -fopenmp mxm_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp mxm_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mxm_openmp.o
mv a.out $HOME/binc/mxm_openmp
#
echo "Normal end of execution."
