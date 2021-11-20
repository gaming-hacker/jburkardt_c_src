#! /bin/bash
#
gcc -c -Wall array_append.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc array_append.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm array_append.o
#
mv a.out array_append
./array_append > array_append.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm array_append
#
echo "Normal end of execution."
