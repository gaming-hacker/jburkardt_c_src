#! /bin/bash
#
gcc -c -Wall -I/$HOME/include midpoint_explicit_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o midpoint_explicit_test midpoint_explicit_test.o /$HOME/libc/midpoint_explicit.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm midpoint_explicit_test.o
#
./midpoint_explicit_test > midpoint_explicit_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm midpoint_explicit_test
#
gnuplot < predator_prey_midpoint_explicit_commands.txt
gnuplot < stiff_midpoint_explicit_commands.txt
#
echo "Normal end of execution."
