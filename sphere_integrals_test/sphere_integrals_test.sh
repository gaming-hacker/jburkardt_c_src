#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sphere_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sphere_integrals_test.o /$HOME/libc/sphere_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_integrals_test.o
#
mv a.out sphere_integrals_test
./sphere_integrals_test > sphere_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_integrals_test
#
echo "Normal end of execution."
