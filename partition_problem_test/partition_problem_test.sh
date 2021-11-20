#! /bin/bash
#
gcc -c -Wall -I/$HOME/include partition_problem_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc partition_problem_test.o /$HOME/libc/partition_problem.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm partition_problem_test.o
#
mv a.out partition_problem_test
./partition_problem_test > partition_problem_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm partition_problem_test
#
echo "Normal end of execution."
