#! /bin/bash
#
gcc -c -Wall -I/$HOME/include test_optimization_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test_optimization_test.o /$HOME/libc/test_optimization.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_optimization_test.o
#
mv a.out test_optimization_test
./test_optimization_test > test_optimization_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_optimization_test
#
echo "Normal end of execution."
