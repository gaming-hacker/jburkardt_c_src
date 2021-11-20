#! /bin/bash
#
gcc -c -Wall -I/$HOME/include cauchy_principal_value_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o cauchy_principal_value_test cauchy_principal_value_test.o /$HOME/libc/cauchy_principal_value.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cauchy_principal_value_test.o
#
./cauchy_principal_value_test > cauchy_principal_value_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cauchy_principal_value_test
#
echo "Normal end of execution."
