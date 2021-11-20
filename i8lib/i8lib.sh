#! /bin/bash
#
cp i8lib.h /$HOME/include
#
gcc -c -Wall i8lib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv i8lib.o ~/libc/i8lib.o
#
echo "Normal end of execution."
