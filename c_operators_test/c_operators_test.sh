#! /bin/bash
#
gcc -c -Wall c_operators_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc c_operators_test.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm c_operators_test.o
#
mv a.out c_operators_test
./c_operators_test > c_operators_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c_operators_test
#
echo "Normal end of execution."
