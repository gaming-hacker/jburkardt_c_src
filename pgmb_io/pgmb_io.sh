#! /bin/bash
#
cp pgmb_io.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include pgmb_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pgmb_io.o ~/libc/pgmb_io.o
#
echo "Normal end of execution."
