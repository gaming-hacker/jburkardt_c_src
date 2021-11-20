#! /bin/bash
#
mpicc -c -Wall quad_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc quad_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quad_mpi.o
#
mv a.out $HOME/binc/quad_mpi
#
echo "Normal end of execution."
