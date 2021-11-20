#! /bin/bash
#
cp r8ge.h /$HOME/include
#
gcc -c -Wall r8ge.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8ge.o ~/libc/r8ge.o
#
echo "Normal end of execution."
