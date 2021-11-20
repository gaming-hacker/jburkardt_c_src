#! /bin/bash
#
cp cycle_brent.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include cycle_brent.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cycle_brent.o ~/libc/cycle_brent.o
#
echo "Normal end of execution."
