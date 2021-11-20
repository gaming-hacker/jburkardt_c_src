#! /bin/bash
#
cp ellipse_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include ellipse_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ellipse_monte_carlo.o ~/libc/ellipse_monte_carlo.o
#
echo "Normal end of execution."
