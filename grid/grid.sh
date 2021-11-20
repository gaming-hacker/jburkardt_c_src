#! /bin/bash
#
cp grid.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv grid.o ~/libc/grid.o
#
echo "Normal end of execution."
