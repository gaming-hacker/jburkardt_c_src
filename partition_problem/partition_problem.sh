#! /bin/bash
#
cp partition_problem.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include partition_problem.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv partition_problem.o ~/libc/partition_problem.o
#
echo "Normal end of execution."
