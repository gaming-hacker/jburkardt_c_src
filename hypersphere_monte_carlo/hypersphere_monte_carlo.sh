#! /bin/bash
#
cp hypersphere_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hypersphere_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypersphere_monte_carlo.o ~/libc/hypersphere_monte_carlo.o
#
echo "Normal end of execution."
