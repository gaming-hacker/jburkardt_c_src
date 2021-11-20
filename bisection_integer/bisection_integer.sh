#! /bin/bash
#
cp bisection_integer.h /$HOME/include
#
gcc -c -Wall bisection_integer.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bisection_integer.o ~/libc/bisection_integer.o
#
echo "Normal end of execution."
