#! /bin/bash
#
cp toms743.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include toms743.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms743.o ~/libc/toms743.o
#
echo "Normal end of execution."
