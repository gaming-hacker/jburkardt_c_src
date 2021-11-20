#! /bin/bash
#
gcc -c -Wall -fopenmp md_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp md_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm md_openmp.o
mv a.out $HOME/binc/md_openmp
#
echo "Normal end of execution."
