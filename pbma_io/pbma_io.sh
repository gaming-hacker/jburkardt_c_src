#! /bin/bash
#
cp pbma_io.h /$HOME/include
#
gcc -c -Wall pbma_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pbma_io.o ~/libc/pbma_io.o
#
echo "Normal end of execution."
