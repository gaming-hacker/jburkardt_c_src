#! /bin/bash
#
gcc -c -Wall -I/$HOME/include black_scholes_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc black_scholes_test.o /$HOME/libc/black_scholes.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm black_scholes_test.o
#
mv a.out black_scholes_test
./black_scholes_test > black_scholes_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm black_scholes_test
#
echo "Normal end of execution."
