#! /bin/bash
#
gcc -o saxpy_openmp_test -Wall -fopenmp saxpy_openmp_test.c -lm
#
rm -f saxpy_openmp_test.txt
#
for threads in 1 2 4 8
do
  echo "Run with "$threads" threads."
  export OMP_NUM_THREADS=$threads
  ./saxpy_openmp_test >> saxpy_openmp_test.txt
  if [ $? -ne 0 ]; then
    echo "Run error."
    exit
  fi
done
#
rm saxpy_openmp_test
#
echo "Normal end of execution."
