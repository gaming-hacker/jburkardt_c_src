#! /bin/bash
#
cp r8row.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include r8row.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8row.o ~/libc/r8row.o
#
echo "Normal end of execution."
