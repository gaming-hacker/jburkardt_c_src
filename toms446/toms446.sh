#! /bin/bash
#
cp toms446.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include toms446.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms446.o ~/libc/toms446.o
#
echo "Normal end of execution."
