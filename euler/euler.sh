#! /bin/bash
#
cp euler.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include euler.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv euler.o ~/libc/euler.o
#
echo "Normal end of execution."
