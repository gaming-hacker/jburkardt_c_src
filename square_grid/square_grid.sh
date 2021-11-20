#! /bin/bash
#
cp square_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include square_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_grid.o ~/libc/square_grid.o
#
echo "Normal end of execution."
