#! /bin/bash
#
cp simplex_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include simplex_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_grid.o ~/libc/simplex_grid.o
#
echo "Normal end of execution."
