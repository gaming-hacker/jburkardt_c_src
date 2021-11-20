#! /bin/bash
#
cp padua.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include padua.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv padua.o ~/libc/padua.o
#
echo "Normal end of execution."
