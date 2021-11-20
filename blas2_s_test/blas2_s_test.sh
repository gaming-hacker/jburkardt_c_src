#! /bin/bash
#
gcc -c -Wall -I$HOME/include blas2_s_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc blas2_s_test.o $HOME/libc/blas2_s.o $HOME/libc/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas2_s_test.o
#
mv a.out blas2_s_test
./blas2_s_test > blas2_s_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas2_s_test
#
echo "Normal end of execution."
