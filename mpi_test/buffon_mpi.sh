#! /bin/bash
#
mpicc -c -Wall buffon_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc buffon_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm buffon_mpi.o
#
mv a.out buffon_mpi
mpirun -v -np 4 ./buffon_mpi > buffon_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm buffon_mpi
#
echo "Normal end of execution."
