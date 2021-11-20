#! /bin/bash
#
mpicc -c -Wall ring_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc ring_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ring_mpi.o
#
mv a.out $HOME/binc/ring_mpi
#
echo "Normal end of execution."

