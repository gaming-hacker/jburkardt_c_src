#! /bin/bash
#
cp nintlib.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include nintlib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv nintlib.o ~/libc/nintlib.o
#
echo "Normal end of execution."
