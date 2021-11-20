#! /bin/bash
#
gcc -c -Wall -I/$HOME/include multigrid_poisson_1d_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc multigrid_poisson_1d_test.o /$HOME/libc/multigrid_poisson_1d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm multigrid_poisson_1d_test.o
#
mv a.out multigrid_poisson_1d_test
./multigrid_poisson_1d_test > multigrid_poisson_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm multigrid_poisson_1d_test
#
echo "Normal end of execution."
