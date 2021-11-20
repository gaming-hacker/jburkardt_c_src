#! /bin/bash
#
cp besselj.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include besselj.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv besselj.o ~/libc/besselj.o
#
echo "Normal end of execution."
