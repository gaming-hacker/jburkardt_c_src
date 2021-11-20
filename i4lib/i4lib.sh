#! /bin/bash
#
cp i4lib.h /$HOME/include
#
gcc -c -Wall i4lib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv i4lib.o ~/libc/i4lib.o
#
echo "Normal end of execution."
