#! /bin/bash
#
cp polygon_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include polygon_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_grid.o ~/libc/polygon_grid.o
#
echo "Normal end of execution."
