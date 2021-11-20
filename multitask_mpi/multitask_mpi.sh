#! /bin/bash
#
mpicc -c -Wall multitask_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc multitask_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm multitask_mpi.o
#
mv a.out $HOME/binc/multitask_mpi
#
echo "Normal end of execution."

