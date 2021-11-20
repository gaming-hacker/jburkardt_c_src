#! /bin/bash
#
gcc -c -Wall -I/$HOME/include polygon_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc polygon_monte_carlo_test.o /$HOME/libc/polygon_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polygon_monte_carlo_test.o
#
mv a.out polygon_monte_carlo_test
./polygon_monte_carlo_test > polygon_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polygon_monte_carlo_test
#
echo "Normal end of execution."
