#! /bin/bash
#
cp box_behnken.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include box_behnken.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv box_behnken.o ~/libc/box_behnken.o
#
echo "Normal end of execution."
