#! /bin/bash
#
cp triangle_integrals.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include triangle_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_integrals.o ~/libc/triangle_integrals.o
#
echo "Normal end of execution."
