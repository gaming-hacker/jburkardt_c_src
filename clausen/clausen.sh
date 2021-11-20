#! /bin/bash
#
cp clausen.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include clausen.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv clausen.o ~/libc/clausen.o
#
echo "Normal end of execution."
