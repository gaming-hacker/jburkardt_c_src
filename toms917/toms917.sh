#! /bin/bash
#
cp toms917.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include toms917.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms917.o ~/libc/toms917.o
#
echo "Normal end of execution."
