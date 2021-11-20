#! /bin/bash
#
cp fastgl.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fastgl.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fastgl.o ~/libc/fastgl.o
#
echo "Normal end of execution."
