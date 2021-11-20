#! /bin/bash
#
cp sphere_triangle_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sphere_triangle_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_triangle_monte_carlo.o ~/libc/sphere_triangle_monte_carlo.o
#
echo "Normal end of execution."
