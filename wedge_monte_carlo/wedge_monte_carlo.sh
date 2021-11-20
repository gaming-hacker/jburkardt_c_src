#! /bin/bash
#
cp wedge_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include wedge_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wedge_monte_carlo.o ~/libc/wedge_monte_carlo.o
#
echo "Normal end of execution."
