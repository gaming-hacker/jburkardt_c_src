#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cc_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o cc_io_test cc_io_test.o /$HOME/libc/cc_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cc_io_test.o
#
./cc_io_test > cc_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cc_io_test
#
echo "Normal end of execution."
