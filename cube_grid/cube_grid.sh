#! /bin/bash
#
cp cube_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cube_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_grid.o ~/libc/cube_grid.o
#
echo "Normal end of execution."
