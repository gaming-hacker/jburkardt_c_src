#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sphere_triangle_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sphere_triangle_monte_carlo_test.o /$HOME/libc/sphere_triangle_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_triangle_monte_carlo_test.o
#
mv a.out sphere_triangle_monte_carlo_test
./sphere_triangle_monte_carlo_test > sphere_triangle_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_triangle_monte_carlo_test
#
echo "Normal end of execution."
