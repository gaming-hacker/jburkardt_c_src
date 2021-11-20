#! /bin/bash
#
gcc -c -Wall -fopenmp satisfy_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp satisfy_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm satisfy_openmp.o
mv a.out $HOME/binc/satisfy_openmp
#
echo "Normal end of execution."
