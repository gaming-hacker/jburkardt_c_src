#! /bin/bash
#
gcc -c -Wall -I/$HOME/include rk4_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc rk4_test.o /$HOME/libc/rk4.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rk4_test.o
#
mv a.out rk4_test
./rk4_test > rk4_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rk4_test
#
gnuplot < predator_commands.txt
#
echo "Normal end of execution."
