#! /bin/bash
#
gcc -c -Wall -I/$HOME/include table_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc table_io_test.o /$HOME/libc/table_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm table_io_test.o
#
mv a.out table_io_test
./table_io_test > table_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm table_io_test
#
echo "Normal end of execution."
