#! /bin/bash
#
cp r8ut.h /$HOME/include
#
gcc -c -Wall r8ut.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8ut.o ~/libc/r8ut.o
#
echo "Normal end of execution."
