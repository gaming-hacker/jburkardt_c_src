#!/bin/bash
#
cp treepack.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include treepack.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv treepack.o ~/libc/treepack.o
#
echo "Normal end of execution."
