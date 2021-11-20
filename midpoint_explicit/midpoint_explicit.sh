#! /bin/bash
#
cp midpoint_explicit.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include midpoint_explicit.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv midpoint_explicit.o ~/libc/midpoint_explicit.o
#
echo "Normal end of execution."
