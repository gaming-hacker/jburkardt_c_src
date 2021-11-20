#! /bin/bash
#
gcc -c -Wall poisson.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc poisson.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm poisson.o
#
mv a.out poisson
./poisson > poisson.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm poisson
#
echo "Normal end of execution."
