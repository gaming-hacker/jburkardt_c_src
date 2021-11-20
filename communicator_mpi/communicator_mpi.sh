#! /bin/bash
#
mpicc -c -Wall communicator_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc communicator_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm communicator_mpi.o
#
mv a.out $HOME/binc/communicator_mpi
#
echo "Normal end of execution."
