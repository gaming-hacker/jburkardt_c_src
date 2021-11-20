#! /bin/bash
#
cp isbn.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include isbn.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv isbn.o ~/libc/isbn.o
#
echo "Normal end of execution."
