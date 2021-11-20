#! /bin/bash
#
cp tetrahedron01_monte_carlo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include tetrahedron01_monte_carlo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron01_monte_carlo.o ~/libc/tetrahedron01_monte_carlo.o
#
echo "Normal end of execution."
