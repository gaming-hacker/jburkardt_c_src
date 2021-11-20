#! /bin/bash
#
cp cube_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cube_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_monte_carlo.o ~/libc/cube_monte_carlo.o
#
echo "Normal end of execution."
