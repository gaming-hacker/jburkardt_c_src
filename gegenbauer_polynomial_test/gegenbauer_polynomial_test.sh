#! /bin/bash
#
gcc -c -Wall -I/$HOME/include gegenbauer_polynomial_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o gegenbauer_polynomial_test gegenbauer_polynomial_test.o /$HOME/libc/gegenbauer_polynomial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gegenbauer_polynomial_test.o
#
./gegenbauer_polynomial_test > gegenbauer_polynomial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm gegenbauer_polynomial_test
#
echo "Normal end of execution."
