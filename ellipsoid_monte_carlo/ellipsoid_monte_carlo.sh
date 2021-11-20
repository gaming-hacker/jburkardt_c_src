#! /bin/bash
#
cp ellipsoid_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include ellipsoid_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ellipsoid_monte_carlo.o ~/libc/ellipsoid_monte_carlo.o
#
echo "Normal end of execution."
