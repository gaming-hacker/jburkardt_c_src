#! /bin/bash
#
mpicc -c -Wall satisfy_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc satisfy_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm satisfy_mpi.o
#
mv a.out $HOME/binc/satisfy_mpi
#
echo "Normal end of execution."

