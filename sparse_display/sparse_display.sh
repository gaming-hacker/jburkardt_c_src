#! /bin/bash
#
cp sparse_display.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sparse_display.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_display.o ~/libc/sparse_display.o
#
echo "Normal end of execution."
