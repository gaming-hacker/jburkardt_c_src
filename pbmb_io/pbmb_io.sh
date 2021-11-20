#! /bin/bash
#
cp pbmb_io.h /$HOME/include
#
gcc -c -Wall pbmb_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pbmb_io.o ~/libc/pbmb_io.o
#
echo "Normal end of execution."
