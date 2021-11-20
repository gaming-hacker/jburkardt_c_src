#! /bin/bash
#
gcc -c -Wall -I/$HOME/include st_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc st_io_test.o /$HOME/libc/st_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm st_io_test.o
#
mv a.out st_io_test
./st_io_test > st_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm st_io_test
#
echo "Normal end of execution."
