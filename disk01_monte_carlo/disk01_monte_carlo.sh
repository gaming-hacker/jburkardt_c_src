#! /bin/bash
#
cp disk01_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include disk01_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk01_monte_carlo.o ~/libc/disk01_monte_carlo.o
#
echo "Normal end of execution."
