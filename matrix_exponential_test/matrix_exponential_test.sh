#! /bin/bash
#
gcc -c -Wall -I/$HOME/include matrix_exponential_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc matrix_exponential_test.o /$HOME/libc/matrix_exponential.o \
                             /$HOME/libc/test_matrix_exponential.o \
                             /$HOME/libc/c8lib.o \
                             /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm matrix_exponential_test.o
#
mv a.out matrix_exponential_test
./matrix_exponential_test > matrix_exponential_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm matrix_exponential_test
#
echo "Normal end of execution."
