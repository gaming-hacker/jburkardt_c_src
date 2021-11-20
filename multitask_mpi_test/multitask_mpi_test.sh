#! /bin/bash
#
mpirun -np 3 $HOME/binc/multitask_mpi > multitask_mpi_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

