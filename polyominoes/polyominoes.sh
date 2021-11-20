#! /bin/bash
#
cp polyominoes.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include polyominoes.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polyominoes.o ~/libc/polyominoes.o
#
echo "Normal end of execution."
