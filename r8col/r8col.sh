#! /bin/bash
#
cp r8col.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include r8col.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8col.o ~/libc/r8col.o
#
echo "Normal end of execution."
