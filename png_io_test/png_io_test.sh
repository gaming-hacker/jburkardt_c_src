#! /bin/bash
#
gcc -c -Wall -I/$HOME/include png_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o png_io_test png_io_test.o /$HOME/libc/png_io.o -lm -lpng
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm png_io_test.o
#
./png_io_test > png_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm png_io_test
#
echo "Normal end of execution."
