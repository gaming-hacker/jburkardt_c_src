#! /bin/bash
#
cp polygon_integrals.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include polygon_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_integrals.o ~/libc/polygon_integrals.o
#
echo "Normal end of execution."
