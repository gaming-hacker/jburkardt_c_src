#! /bin/bash
#
cp hypercube_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include hypercube_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypercube_monte_carlo.o ~/libc/hypercube_monte_carlo.o
#
echo "Normal end of execution."
