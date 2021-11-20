#! /bin/bash
#
mpicc -c -Wall poisson_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc poisson_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm poisson_mpi.o
#
mv a.out $HOME/binc/poisson
#
echo "Normal end of execution."

