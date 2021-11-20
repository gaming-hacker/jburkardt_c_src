#! /bin/bash
#
gcc -c -Wall -I/$HOME/include square_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc square_integrals_test.o /$HOME/libc/square_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm square_integrals_test.o
#
mv a.out square_integrals_test
./square_integrals_test > square_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm square_integrals_test
#
echo "Normal end of execution."
