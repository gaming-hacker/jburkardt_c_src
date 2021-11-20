#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ellipsoid_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o ellipsoid_monte_carlo_test ellipsoid_monte_carlo_test.o /$HOME/libc/ellipsoid_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ellipsoid_monte_carlo_test.o
#
./ellipsoid_monte_carlo_test > ellipsoid_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ellipsoid_monte_carlo_test
#
echo "Normal end of execution."
