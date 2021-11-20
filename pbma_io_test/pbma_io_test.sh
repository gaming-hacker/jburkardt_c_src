#! /bin/bash
#
gcc -c -Wall -I/$HOME/include pbma_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pbma_io_test.o /$HOME/libc/pbma_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pbma_io_test.o
#
mv a.out pbma_io_test
./pbma_io_test > pbma_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pbma_io_test
#
echo "Normal end of execution."
