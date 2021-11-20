#! /bin/bash
#
gcc -c -Wall -fopenmp timer_omp_get_wtime.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o timer_omp_get_wtime -fopenmp timer_omp_get_wtime.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm timer_omp_get_wtime.o
#
./timer_omp_get_wtime > timer_omp_get_wtime.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm timer_omp_get_wtime
#
echo "Normal end of execution."
