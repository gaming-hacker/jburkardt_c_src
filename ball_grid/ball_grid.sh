#! /bin/bash
#
cp ball_grid.h /$HOME/include
#
gcc -c -Wall ball_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ball_grid.o ~/libc/ball_grid.o
#
echo "Normal end of execution."
