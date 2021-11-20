#! /bin/bash
#
cp triangle_io.h /$HOME/include
#
gcc -c -Wall triangle_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_io.o ~/libc/triangle_io.o
#
echo "Normal end of execution."
