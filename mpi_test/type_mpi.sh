#! /bin/bash
#
mpicc -c -Wall type_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc type_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm type_mpi.o
#
mv a.out type_mpi
mpirun -v -np 4 ./type_mpi > type_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm type_mpi
#
echo "Normal end of execution."
