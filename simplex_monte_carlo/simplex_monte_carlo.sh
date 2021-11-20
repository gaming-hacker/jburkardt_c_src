#! /bin/bash
#
cp simplex_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include simplex_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_monte_carlo.o ~/libc/simplex_monte_carlo.o
#
echo "Normal end of execution."
