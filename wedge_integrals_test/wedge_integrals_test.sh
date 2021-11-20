#! /bin/bash
#
gcc -c -Wall -I/$HOME/include wedge_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o wedge_integrals_test wedge_integrals_test.o /$HOME/libc/wedge_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wedge_integrals_test.o
#
./wedge_integrals_test > wedge_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wedge_integrals_test
#
echo "Normal end of execution."
