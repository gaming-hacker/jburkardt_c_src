#! /bin/bash
#
cp png_io.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include png_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv png_io.o ~/libc/png_io.o
#
echo "Normal end of execution."
