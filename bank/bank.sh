#! /bin/bash
#
cp bank.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include bank.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bank.o ~/libc/bank.o
#
echo "Normal end of execution."
