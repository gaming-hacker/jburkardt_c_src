#! /bin/bash
#
gcc -c -Wall -fopenmp fft_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp fft_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fft_openmp.o
mv a.out $HOME/binc/fft_openmp
#
echo "Normal end of execution."
