#! /bin/bash
#
cp cell.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cell.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cell.o ~/libc/cell.o
#
echo "Normal end of execution."
