#! /bin/bash
#
gcc -c -Wall -I/$HOME/include disk_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc disk_monte_carlo_test.o /$HOME/libc/disk_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm disk_monte_carlo_test.o
#
mv a.out disk_monte_carlo_test
./disk_monte_carlo_test > disk_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm disk_monte_carlo_test
#
echo "Normal end of execution."
