#! /bin/bash
#
gcc -c -Wall -I/$HOME/include line_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc line_monte_carlo_test.o /$HOME/libc/line_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm line_monte_carlo_test.o
#
mv a.out line_monte_carlo_test
./line_monte_carlo_test > line_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_monte_carlo_test
#
echo "Normal end of execution."
