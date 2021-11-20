#! /bin/bash
#
cp normal.h /$HOME/include
#
gcc -c -Wall normal.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv normal.o ~/libc/normal.o
#
echo "Normal end of execution."
