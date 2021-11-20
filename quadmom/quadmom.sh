#! /bin/bash
#
cp quadmom.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include quadmom.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadmom.o ~/libc/quadmom.o
#
echo "Normal end of execution."
