#! /bin/bash
#
cp collatz_recursive.h /$HOME/include
#
gcc -c -Wall collatz_recursive.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv collatz_recursive.o ~/libc/collatz_recursive.o
#
echo "Normal end of execution."
