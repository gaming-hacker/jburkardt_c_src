#! /bin/bash
#
cp ranlib.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include ranlib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ranlib.o ~/libc/ranlib.o
#
echo "Normal end of execution."
