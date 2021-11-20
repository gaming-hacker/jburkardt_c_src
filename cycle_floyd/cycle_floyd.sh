#! /bin/bash
#
cp cycle_floyd.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cycle_floyd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cycle_floyd.o ~/libc/cycle_floyd.o
#
echo "Normal end of execution."
