#! /bin/bash
#
gcc -c -Wall -I/$HOME/include wedge_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o wedge_monte_carlo_test wedge_monte_carlo_test.o /$HOME/libc/wedge_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wedge_monte_carlo_test.o
#
./wedge_monte_carlo_test > wedge_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wedge_monte_carlo_test
#
echo "Normal end of execution."
