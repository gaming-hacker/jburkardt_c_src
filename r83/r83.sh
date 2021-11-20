#! /bin/bash
#
cp r83.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include r83.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r83.o ~/libc/r83.o
#
echo "Normal end of execution."
