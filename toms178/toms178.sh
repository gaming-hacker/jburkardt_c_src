#! /bin/bash
#
cp toms178.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include toms178.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms178.o ~/libc/toms178.o
#
echo "Normal end of execution."
