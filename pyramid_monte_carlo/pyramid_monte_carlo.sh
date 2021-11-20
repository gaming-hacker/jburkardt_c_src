#! /bin/bash
#
cp pyramid_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include pyramid_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pyramid_monte_carlo.o ~/libc/pyramid_monte_carlo.o
#
echo "Normal end of execution."
