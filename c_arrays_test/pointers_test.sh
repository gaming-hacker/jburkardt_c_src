#! /bin/bash
#
gcc -c -Wall pointers_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o pointers_test pointers_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm pointers.o
#
./pointers_test > pointers_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pointers_test
#
echo "Normal end of execution."
