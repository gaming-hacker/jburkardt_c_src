#! /bin/bash
#
gcc -c -Wall -I/$HOME/include ode_moshier_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ode_moshier_test.o -L/$HOME/libc -lode_moshier -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ode_moshier_test.o
#
mv a.out ode_moshier_test
./ode_moshier_test < ode_moshier_test_input.txt > ode_moshier_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ode_moshier_test
#
echo "Normal end of execution."
