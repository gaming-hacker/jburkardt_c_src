#! /bin/bash
#
cp fd1d_heat_steady.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fd1d_heat_steady.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fd1d_heat_steady.o ~/libc/fd1d_heat_steady.o
#
echo "Normal end of execution."
