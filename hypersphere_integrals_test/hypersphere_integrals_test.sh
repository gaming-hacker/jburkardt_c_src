#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hypersphere_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hypersphere_integrals_test.o /$HOME/libc/hypersphere_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hypersphere_integrals_test.o
#
mv a.out hypersphere_integrals_test
./hypersphere_integrals_test > hypersphere_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hypersphere_integrals_test
#
echo "Normal end of execution."
