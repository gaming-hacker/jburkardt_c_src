#! /bin/bash
#
gcc -c -Wall -I/$HOME/include index_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc index_test.o /$HOME/libc/index.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm index_test.o
#
mv a.out index_test
./index_test > index_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm index_test
#
echo "Normal end of execution."
