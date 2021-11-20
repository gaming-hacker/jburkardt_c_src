#! /bin/bash
#
cp triangle_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_monte_carlo.o ~/libc/triangle_monte_carlo.o
#
echo "Normal end of execution."
