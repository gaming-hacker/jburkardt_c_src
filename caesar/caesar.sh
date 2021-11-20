#! /bin/bash
#
cp caesar.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include caesar.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv caesar.o ~/libc/caesar.o
#
echo "Normal end of execution."
