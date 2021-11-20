#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hyperball_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hyperball_integrals_test.o /$HOME/libc/hyperball_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hyperball_integrals_test.o
#
mv a.out hyperball_integrals_test
./hyperball_integrals_test > hyperball_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hyperball_integrals_test
#
echo "Normal end of execution."
