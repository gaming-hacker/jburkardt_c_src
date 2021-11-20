#! /bin/bash
#
cp stroud.h /$HOME/include
#
gcc -c -Wall stroud.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stroud.o ~/libc/stroud.o
#
echo "Normal end of execution."
