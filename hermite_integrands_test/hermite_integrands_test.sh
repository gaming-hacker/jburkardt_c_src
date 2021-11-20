#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hermite_integrands_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hermite_integrands_test.o /$HOME/libc/hermite_integrands.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hermite_integrands_test.o
#
mv a.out hermite_integrands_test
./hermite_integrands_test > hermite_integrands_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hermite_integrands_test
#
echo "Normal end of execution."
