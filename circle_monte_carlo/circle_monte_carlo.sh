#! /bin/bash
#
cp circle_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include circle_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_monte_carlo.o ~/libc/circle_monte_carlo.o
#
echo "Normal end of execution."
