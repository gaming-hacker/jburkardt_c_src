#! /bin/bash
#
cp triangle_properties.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include triangle_properties.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_properties.o ~/libc/triangle_properties.o
#
echo "Normal end of execution."
