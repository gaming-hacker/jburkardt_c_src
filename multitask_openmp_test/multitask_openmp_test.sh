#! /bin/bash
#
echo "Run with 1 thread."
export OMP_NUM_THREADS=1
$HOME/binc/multitask_openmp > multitask_openmp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Run with 2 threads."
export OMP_NUM_THREADS=2
$HOME/binc/multitask_openmp >> multitask_openmp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Run with 4 threads."
export OMP_NUM_THREADS=4
$HOME/binc/multitask_openmp >> multitask_openmp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
