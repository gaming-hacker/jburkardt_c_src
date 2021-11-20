#! /bin/bash
#
cp pyramid_grid.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include pyramid_grid.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pyramid_grid.o ~/libc/pyramid_grid.o
#
echo "Normal end of execution."
