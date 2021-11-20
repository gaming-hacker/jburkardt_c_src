#! /bin/bash
#
gcc -c -Wall -fopenmp image_denoise_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp image_denoise_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm image_denoise_openmp.o
mv a.out $HOME/binc/image_denoise_openmp
#
echo "Normal end of execution."
