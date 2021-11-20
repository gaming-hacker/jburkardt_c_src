#! /bin/bash
#
cp simplex_coordinates.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include simplex_coordinates.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_coordinates.o ~/libc/simplex_coordinates.o
#
echo "Normal end of execution."
