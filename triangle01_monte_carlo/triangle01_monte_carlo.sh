#! /bin/bash
#
cp triangle01_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangle01_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle01_monte_carlo.o ~/libc/triangle01_monte_carlo.o
#
echo "Normal end of execution."
