#! /bin/bash
#
cp sphere_quad.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include sphere_quad.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_quad.o ~/libc/sphere_quad.o
#
echo "Normal end of execution."
