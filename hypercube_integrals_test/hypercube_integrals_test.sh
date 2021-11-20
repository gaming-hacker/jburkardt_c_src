#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hypercube_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hypercube_integrals_test.o /$HOME/libc/hypercube_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hypercube_integrals_test.o
#
mv a.out hypercube_integrals_test
./hypercube_integrals_test > hypercube_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hypercube_integrals_test
#
echo "Normal end of execution."
