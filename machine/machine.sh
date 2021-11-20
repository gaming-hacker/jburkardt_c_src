#! /bin/bash
#
cp machine.h /$HOME/include
#
gcc -c -Wall machine.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv machine.o ~/libc/machine.o
#
echo "Normal end of execution."
