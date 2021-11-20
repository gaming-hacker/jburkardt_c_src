#! /bin/bash
#
cp divdif.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include divdif.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv divdif.o ~/libc/divdif.o
#
echo "Normal end of execution."
