#! /bin/bash
#
cp fd2d_heat_steady.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include fd2d_heat_steady.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fd2d_heat_steady.o ~/libc/fd2d_heat_steady.o
#
echo "Normal end of execution."
