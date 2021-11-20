#! /bin/bash
#
gcc -c -Wall -fopenmp hello_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp hello_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hello_openmp.o
mv a.out $HOME/binc/hello_openmp
#
echo "Normal end of execution."
