#! /bin/bash
#
gcc -c -Wall -I/$HOME/include burgers_solution_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc burgers_solution_test.o /$HOME/libc/burgers_solution.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm burgers_solution_test.o
#
mv a.out burgers_solution_test
./burgers_solution_test > burgers_solution_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm burgers_solution_test
#
echo "Normal end of execution."
