#! /bin/bash
#
cp hyperball_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include hyperball_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hyperball_monte_carlo.o ~/libc/hyperball_monte_carlo.o
#
echo "Normal end of execution."
