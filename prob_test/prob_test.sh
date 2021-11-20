#! /bin/bash
#
gcc -c -Wall -I/$HOME/include prob_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc prob_test.o /$HOME/libc/prob.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm prob_test.o
#
mv a.out prob_test
./prob_test > prob_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm prob_test
#
echo "Normal end of execution."
