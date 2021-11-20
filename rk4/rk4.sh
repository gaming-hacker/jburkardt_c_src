#! /bin/bash
#
cp rk4.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include rk4.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rk4.o ~/libc/rk4.o
#
echo "Normal end of execution."
