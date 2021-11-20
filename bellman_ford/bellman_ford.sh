#! /bin/bash
#
cp bellman_ford.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include bellman_ford.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bellman_ford.o ~/libc/bellman_ford.o
#
echo "Normal end of execution."
