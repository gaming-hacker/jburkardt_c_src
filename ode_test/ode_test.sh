#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ode_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ode_test.o /$HOME/libc/ode.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ode_test.o
#
mv a.out ode_test
./ode_test > ode_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ode_test
#
echo "Normal end of execution."
