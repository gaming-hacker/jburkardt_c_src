#! /bin/bash
#
cp toms515.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include toms515.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms515.o ~/libc/toms515.o
#
echo "Normal end of execution."
