#! /bin/bash
#
cp ellipse_grid.h /$HOME/include
#
gcc -c -Wall ellipse_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ellipse_grid.o ~/libc/ellipse_grid.o
#
echo "Normal end of execution."
