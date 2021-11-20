#! /bin/bash
#
gcc -c -Wall -I/$HOME/include mm_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mm_io_test.o /$HOME/libc/mm_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mm_io_test.o
#
mv a.out mm_io_test
./mm_io_test > mm_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm mm_io_test
#
echo "Normal end of execution."
