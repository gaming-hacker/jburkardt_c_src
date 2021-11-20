#! /bin/bash
#
cp wedge_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include wedge_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wedge_grid.o ~/libc/wedge_grid.o
#
echo "Normal end of execution."
