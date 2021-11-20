#! /bin/bash
#
cp upc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include upc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv upc.o ~/libc/upc.o
#
echo "Normal end of execution."
