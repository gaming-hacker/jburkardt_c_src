#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ppma_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ppma_io_test.o /$HOME/libc/ppma_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ppma_io_test.o
#
mv a.out ppma_io_test
./ppma_io_test > ppma_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ppma_io_test
#
echo "Normal end of execution."
