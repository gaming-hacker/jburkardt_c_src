#! /bin/bash
#
cp fem1d_heat_steady.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fem1d_heat_steady.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem1d_heat_steady.o ~/libc/fem1d_heat_steady.o
#
echo "Normal end of execution."
