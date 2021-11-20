#! /bin/bash
#
cp pbmlib.h /$HOME/include
#
gcc -c -Wall pbmlib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pbmlib.o ~/libc/pbmlib.o
#
echo "Normal end of execution."
