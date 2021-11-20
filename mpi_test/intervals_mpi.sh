#! /bin/bash
#
mpicc -c -Wall intervals_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc intervals_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm intervals_mpi.o
#
mv a.out intervals_mpi
mpirun -v -np 4 ./intervals_mpi > intervals_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm intervals_mpi
#
echo "Normal end of execution."
