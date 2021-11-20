#! /bin/bash
#
cp line_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include line_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_grid.o ~/libc/line_grid.o
#
echo "Normal end of execution."
