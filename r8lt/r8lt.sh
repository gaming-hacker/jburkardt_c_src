#! /bin/bash
#
cp r8lt.h /$HOME/include
#
gcc -c -Wall r8lt.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8lt.o ~/libc/r8lt.o
#
echo "Normal end of execution."
