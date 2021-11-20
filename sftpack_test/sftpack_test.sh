#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sftpack_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sftpack_test.o /$HOME/libc/sftpack.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sftpack_test.o
#
mv a.out sftpack_test
./sftpack_test > sftpack_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sftpack_test
#
echo "Normal end of execution."
