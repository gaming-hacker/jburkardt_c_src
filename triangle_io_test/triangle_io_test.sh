#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_io_test.o /$HOME/libc/triangle_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_io_test.o
#
mv a.out triangle_io_test
./triangle_io_test > triangle_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_io_test
#
echo "Normal end of execution."
