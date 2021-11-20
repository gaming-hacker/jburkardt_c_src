#! /bin/bash
#
mpicc -c -Wall prime_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc prime_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm prime_mpi.o
#
mv a.out $HOME/binc/prime_mpi
#
echo "Normal end of execution."
