#! /bin/bash
#
gcc -c -Wall -I/$HOME/include floyd_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc floyd_test.o /$HOME/libc/floyd.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm floyd_test.o
#
mv a.out floyd_test
./floyd_test > floyd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm floyd_test
#
echo "Normal end of execution."
