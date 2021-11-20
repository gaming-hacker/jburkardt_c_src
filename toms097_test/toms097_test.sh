#! /bin/bash
#
gcc -c -Wall -I/$HOME/include toms097_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc toms097_test.o /$HOME/libc/toms097.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms097_test.o
#
mv a.out toms097_test
./toms097_test > toms097_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms097_test
#
echo "Normal end of execution."
