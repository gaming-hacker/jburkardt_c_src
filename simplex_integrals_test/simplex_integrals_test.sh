#! /bin/bash
#
gcc -c -Wall -I/$HOME/include simplex_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc simplex_integrals_test.o /$HOME/libc/simplex_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simplex_integrals_test.o
#
mv a.out simplex_integrals_test
./simplex_integrals_test > simplex_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simplex_integrals_test
#
echo "Normal end of execution."
