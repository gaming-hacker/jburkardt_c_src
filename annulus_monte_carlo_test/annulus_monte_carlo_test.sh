#! /bin/bash
#
gcc -c -I/$HOME/include annulus_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o annulus_monte_carlo_test annulus_monte_carlo_test.o -L/$HOME/libc -lannulus_monte_carlo -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm annulus_monte_carlo_test.o
#
./annulus_monte_carlo_test > annulus_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm annulus_monte_carlo_test
#
echo "Normal end of execution."
