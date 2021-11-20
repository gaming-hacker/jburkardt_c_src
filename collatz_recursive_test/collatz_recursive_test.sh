#! /bin/bash
#
gcc -c -Wall -I/$HOME/include collatz_recursive_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc collatz_recursive_test.o /$HOME/libc/collatz_recursive.o -lm
if [ $? -ne 0 ]; then
  echo "Errors linking and loading collatz_recursive_test.o."
  exit
fi
rm collatz_recursive_test.o
#
mv a.out collatz_recursive_test
./collatz_recursive_test > collatz_recursive_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm collatz_recursive_test
#
echo "Normal end of execution."
