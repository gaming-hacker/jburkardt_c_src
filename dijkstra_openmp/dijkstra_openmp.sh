#! /bin/bash
#
gcc -c -Wall -fopenmp dijkstra_openmp.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -fopenmp dijkstra_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm dijkstra_openmp.o
mv a.out $HOME/binc/dijkstra_openmp
#
echo "Normal end of execution."
