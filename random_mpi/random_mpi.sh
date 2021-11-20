#! /bin/bash
#
mpicc -c -Wall random_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc random_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm random_mpi.o
#
mv a.out $HOME/binc/random_mpi
#
echo "Normal end of execution."

