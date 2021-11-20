#! /bin/bash
#
cp machar.h /$HOME/include
#
gcc -c -Wall machar.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv machar.o ~/libc/machar.o
#
echo "Normal end of execution."
