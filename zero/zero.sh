#! /bin/bash
#
cp zero.h /$HOME/include
#
gcc -c -Wall zero.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv zero.o ~/libc/zero.o
#
echo "Normal end of execution."
