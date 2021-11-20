#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hypersphere_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hypersphere_monte_carlo_test.o /$HOME/libc/hypersphere_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hypersphere_monte_carlo_test.o
#
mv a.out hypersphere_monte_carlo_test
./hypersphere_monte_carlo_test > hypersphere_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hypersphere_monte_carlo_test
#
echo "Normal end of execution."
