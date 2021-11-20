#! /bin/bash
#
mpicc -c -Wall search_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc search_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm search_mpi.o
#
mv a.out $HOME/binc/search_mpi
#
echo "Normal end of execution."

