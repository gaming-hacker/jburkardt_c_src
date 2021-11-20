#! /bin/bash
#
gcc -c -Wall -I/$HOME/include polygon_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc polygon_integrals_test.o /$HOME/libc/polygon_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polygon_integrals_test.o
#
mv a.out polygon_integrals_test
./polygon_integrals_test > polygon_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polygon_integrals_test
#
echo "Normal end of execution."
