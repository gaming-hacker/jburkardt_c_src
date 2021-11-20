#! /bin/bash
#
cp fd1d_heat_explicit.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fd1d_heat_explicit.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fd1d_heat_explicit.o ~/libc/fd1d_heat_explicit.o
#
echo "Normal end of execution."
