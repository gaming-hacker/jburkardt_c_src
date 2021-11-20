#! /bin/bash
#
cp byname.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include byname.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv byname.o ~/libc/byname.o
#
echo "Normal end of execution."
