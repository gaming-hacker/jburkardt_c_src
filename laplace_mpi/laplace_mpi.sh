#! /bin/bash
#
mpicc -c laplace_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc laplace_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm laplace_mpi.o
#
mv a.out $HOME/binc/laplace_mpi
#
echo "Normal end of execution."
