#! /bin/bash
#
cp correlation.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include correlation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv correlation.o ~/libc/correlation.o
#
echo "Normal end of execution."
