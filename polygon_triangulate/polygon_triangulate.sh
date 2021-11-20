#! /bin/bash
#
cp polygon_triangulate.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include polygon_triangulate.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_triangulate.o ~/libc/polygon_triangulate.o
#
echo "Normal end of execution."
