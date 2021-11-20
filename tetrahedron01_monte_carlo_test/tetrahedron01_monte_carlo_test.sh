#! /bin/bash
#
gcc -c -Wall -I/$HOME/include tetrahedron01_monte_carlo_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc tetrahedron01_monte_carlo_test.o /$HOME/libc/tetrahedron01_monte_carlo.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tetrahedron01_monte_carlo_test.o
#
mv a.out tetrahedron01_monte_carlo_test
./tetrahedron01_monte_carlo_test > tetrahedron01_monte_carlo_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tetrahedron01_monte_carlo_test
#
echo "Normal end of execution."
