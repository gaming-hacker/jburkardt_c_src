#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_eigen_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_eigen_test.o /$HOME/libc/test_eigen.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_eigen_test.o
#
mv a.out test_eigen_test
./test_eigen_test > test_eigen_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_eigen_test
#
echo "Normal end of execution."
