#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle01_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle01_monte_carlo_test.o /$HOME/libc/triangle01_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle01_monte_carlo_test.o
#
mv a.out triangle01_monte_carlo_test
./triangle01_monte_carlo_test > triangle01_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle01_monte_carlo_test
#
echo "Normal end of execution."
