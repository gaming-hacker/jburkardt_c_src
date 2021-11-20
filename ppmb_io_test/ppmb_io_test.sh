#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ppmb_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ppmb_io_test.o /$HOME/libc/ppmb_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ppmb_io_test.o
#
mv a.out ppmb_io_test
./ppmb_io_test > ppmb_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ppmb_io_test
#
echo "Normal end of execution."
