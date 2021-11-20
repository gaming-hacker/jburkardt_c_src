#! /bin/bash
#
cp test_optimization.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_optimization.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_optimization.o ~/libc/test_optimization.o
#
echo "Normal end of execution."
