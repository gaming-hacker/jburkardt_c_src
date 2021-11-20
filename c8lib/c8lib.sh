#! /bin/bash
#
cp c8lib.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include c8lib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv c8lib.o ~/libc/c8lib.o
#
echo "Normal end of execution."
