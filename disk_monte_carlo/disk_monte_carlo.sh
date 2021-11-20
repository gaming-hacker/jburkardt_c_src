#! /bin/bash
#
cp disk_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include disk_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk_monte_carlo.o ~/libc/disk_monte_carlo.o
#
echo "Normal end of execution."
