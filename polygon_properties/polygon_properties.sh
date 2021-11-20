#! /bin/bash
#
cp polygon_properties.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include polygon_properties.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_properties.o ~/libc/polygon_properties.o
#
echo "Normal end of execution."
