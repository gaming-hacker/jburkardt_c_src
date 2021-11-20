#! /bin/bash
#
mpicc -c -Wall heat_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc heat_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm heat_mpi.o
#
mv a.out $HOME/binc/heat_mpi
#
echo "Normal end of execution."

