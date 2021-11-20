#! /bin/bash
#
cp line_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include line_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_monte_carlo.o ~/libc/line_monte_carlo.o
#
echo "Normal end of execution."
