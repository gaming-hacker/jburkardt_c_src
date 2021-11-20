#! /bin/bash
#
gcc -c -Wall -I/$HOME/include laguerre_integrands_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc laguerre_integrands_test.o /$HOME/libc/laguerre_integrands.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm laguerre_integrands_test.o
#
mv a.out laguerre_integrands_test
./laguerre_integrands_test > laguerre_integrands_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm laguerre_integrands_test
#
echo "Normal end of execution."
