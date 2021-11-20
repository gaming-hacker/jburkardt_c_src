#! /bin/bash
#
cp sphere_stereograph.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include sphere_stereograph.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_stereograph.o ~/libc/sphere_stereograph.o
#
echo "Normal end of execution."
