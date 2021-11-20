#! /bin/bash
#
cp triangle_svg.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include triangle_svg.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_svg.o ~/libc/triangle_svg.o
#
echo "Normal end of execution."
