#! /bin/bash
#
cp sphere_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include sphere_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_monte_carlo.o ~/libc/sphere_monte_carlo.o
#
echo "Normal end of execution."
