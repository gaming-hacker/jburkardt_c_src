#! /bin/bash
#
cp circle_arc_grid.h /$HOME/include
#
gcc -c -Wall circle_arc_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_arc_grid.o ~/libc/circle_arc_grid.o
#
echo "Normal end of execution."
