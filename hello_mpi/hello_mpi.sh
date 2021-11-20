#! /bin/bash
#
mpicc -c -Wall hello_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc hello_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hello_mpi.o
#
mv a.out $HOME/binc/hello_mpi
#
echo "Normal end of execution."

