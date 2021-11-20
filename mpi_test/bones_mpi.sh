#! /bin/bash
#
mpicc -c -Wall bones_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc bones_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm bones_mpi.o
#
mv a.out bones_mpi
mpirun -v -np 4 ./bones_mpi > bones_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bones_mpi
#
echo "Normal end of execution."
