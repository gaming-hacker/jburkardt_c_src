#! /bin/bash
#
mpicc -c -Wall sum_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc sum_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm sum_mpi.o
#
mv a.out sum_mpi
mpirun -v -np 4 ./sum_mpi > sum_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sum_mpi
#
echo "Normal end of execution."
