#! /bin/bash
#
gcc -c -Wall -I$HOME/include linpack_s_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc linpack_s_test.o $HOME/libc/linpack_s.o $HOME/libc/blas1_s.o $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm linpack_s_test.o
#
mv a.out linpack_s_test
./linpack_s_test > linpack_s_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm linpack_s_test
#
echo "Normal end of execution."
