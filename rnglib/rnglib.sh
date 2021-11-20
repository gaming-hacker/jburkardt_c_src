#! /bin/bash
#
cp rnglib.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include rnglib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rnglib.o ~/libc/rnglib.o
#
echo "Normal end of execution."
