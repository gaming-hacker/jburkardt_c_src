#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hermite_cubic_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hermite_cubic_test.o /$HOME/libc/hermite_cubic.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hermite_cubic_test.o
#
mv a.out hermite_cubic_test
./hermite_cubic_test > hermite_cubic_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hermite_cubic_test
#
echo "Normal end of execution."
