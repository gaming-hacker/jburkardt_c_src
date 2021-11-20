#! /bin/bash
#
cp sphere_triangle_quad.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include sphere_triangle_quad.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_triangle_quad.o ~/libc/sphere_triangle_quad.o
#
echo "Normal end of execution."
