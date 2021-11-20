#! /bin/bash
#
gcc -c -Wall -I/$HOME/include circle_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc circle_integrals_test.o /$HOME/libc/circle_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm circle_integrals_test.o
#
mv a.out circle_integrals_test
./circle_integrals_test > circle_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm circle_integrals_test
#
echo "Normal end of execution."
