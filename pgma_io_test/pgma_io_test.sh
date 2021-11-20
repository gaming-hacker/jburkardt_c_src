#! /bin/bash
#
gcc -c -Wall -I/$HOME/include pgma_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pgma_io_test.o /$HOME/libc/pgma_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pgma_io_test.o
#
mv a.out pgma_io_test
./pgma_io_test > pgma_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pgma_io_test
#
echo "Normal end of execution."
