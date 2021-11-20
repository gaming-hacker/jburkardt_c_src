#! /bin/bash
#
mpirun -np 8 $HOME/binc/hello_mpi > hello_mpi_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

