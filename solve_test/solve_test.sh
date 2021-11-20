#! /bin/bash
#
gcc -c -Wall -I/$HOME/include solve_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc solve_test.o /$HOME/libc/solve.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm solve_test.o
#
mv a.out solve_test
./solve_test > solve_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm solve_test
#
echo "Normal end of execution."
