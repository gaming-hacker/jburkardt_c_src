#! /bin/bash
#
gcc -c -Wall -fopenmp ziggurat_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp ziggurat_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ziggurat_openmp.o
mv a.out $HOME/binc/ziggurat_openmp
#
#
echo "Normal end of execution."
