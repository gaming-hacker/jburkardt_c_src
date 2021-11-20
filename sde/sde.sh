#! /bin/bash
#
cp sde.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sde.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sde.o ~/libc/sde.o
#
echo "Normal end of execution."
