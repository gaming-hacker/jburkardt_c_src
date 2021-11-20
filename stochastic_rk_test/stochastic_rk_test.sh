#! /bin/bash
#
gcc -c -Wall -I/$HOME/include stochastic_rk_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc stochastic_rk_test.o /$HOME/libc/stochastic_rk.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stochastic_rk_test.o
#
mv a.out stochastic_rk_test
./stochastic_rk_test > stochastic_rk_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stochastic_rk_test
#
echo "Normal end of execution."
