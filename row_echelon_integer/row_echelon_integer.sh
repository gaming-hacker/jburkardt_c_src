#! /bin/bash
#
cp row_echelon_integer.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include row_echelon_integer.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv row_echelon_integer.o ~/libc/row_echelon_integer.o
#
echo "Normal end of execution."
