#! /bin/bash
#
mpicc -c -Wall quadrature_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc quadrature_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quadrature_mpi.o
#
mv a.out quadrature_mpi
mpirun -v -np 4 ./quadrature_mpi > quadrature_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadrature_mpi
#
echo "Normal end of execution."
