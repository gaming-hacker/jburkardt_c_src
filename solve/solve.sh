#! /bin/bash
#
cp solve.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include solve.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv solve.o ~/libc/solve.o
#
echo "Normal end of execution."
