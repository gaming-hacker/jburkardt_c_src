#! /bin/bash
#
mpicc -c -Wall wave_mpi.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicc wave_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wave_mpi.o
#
mv a.out $HOME/binc/wave_mpi
#
echo "Normal end of execution."
