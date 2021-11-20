#! /bin/bash
#
gcc -c -Wall -I/$HOME/include task_division_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc task_division_test.o /$HOME/libc/task_division.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm task_division_test.o
#
mv a.out task_division_test
./task_division_test > task_division_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm task_division_test
#
echo "Normal end of execution."
