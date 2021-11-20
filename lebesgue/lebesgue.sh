#! /bin/bash
#
cp lebesgue.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include lebesgue.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lebesgue.o ~/libc/lebesgue.o
#
echo "Normal end of execution."
