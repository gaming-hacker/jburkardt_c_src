#!/bin/bash
#
gcc -c -Wall -I/$HOME/include treepack_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc treepack_test.o /$HOME/libc/treepack.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm treepack_test.o
#
mv a.out treepack_test
./treepack_test > treepack_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm treepack_test
#
echo "Normal end of execution."
