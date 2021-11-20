#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_matrix_exponential_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_matrix_exponential_test.o /$HOME/libc/test_matrix_exponential.o \
                                  /$HOME/libc/r8lib.o \
                                  /$HOME/libc/c8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_matrix_exponential_test.o
#
mv a.out test_matrix_exponential_test
./test_matrix_exponential_test > test_matrix_exponential_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_matrix_exponential_test
#
echo "Normal end of execution."
