#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cblas_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc cblas_test.o -L$HOME/libc -lcblas -lf2c -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm cblas_test.o
#
mv a.out cblas_test
./cblas_test > cblas_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
rm cblas_test
#
echo "Normal end of execution."

