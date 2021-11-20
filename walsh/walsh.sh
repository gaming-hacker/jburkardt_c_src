#! /bin/bash
#
cp walsh.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include walsh.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv walsh.o ~/libc/walsh.o
#
echo "Normal end of execution."
