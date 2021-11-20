#! /bin/bash
#
gcc -c -Wall -I/$HOME/include subset_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc subset_test.o /$HOME/libc/subset.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm subset_test.o
#
mv a.out subset_test
./subset_test > subset_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm subset_test
#
echo "Normal end of execution."
