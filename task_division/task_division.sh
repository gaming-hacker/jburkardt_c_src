#! /bin/bash
#
cp task_division.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include task_division.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv task_division.o ~/libc/task_division.o
#
echo "Normal end of execution."
