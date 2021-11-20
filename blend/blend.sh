#! /bin/bash
#
cp blend.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include blend.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blend.o ~/libc/blend.o
#
echo "Normal end of execution."
