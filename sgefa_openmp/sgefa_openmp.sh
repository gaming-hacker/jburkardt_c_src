#! /bin/bash
#
gcc -c -Wall -fopenmp sgefa_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp sgefa_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm sgefa_openmp.o
mv a.out $HOME/binc/sgefa_openmp
#
echo "Normal end of execution."
