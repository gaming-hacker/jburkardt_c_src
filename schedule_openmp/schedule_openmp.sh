#! /bin/bash
#
gcc -c -Wall -fopenmp schedule_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp schedule_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm schedule_openmp.o
mv a.out $HOME/binc/schedule_openmp
#
echo "Normal end of execution."
