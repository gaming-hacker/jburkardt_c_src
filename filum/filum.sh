#! /bin/bash
#
cp filum.h /$HOME/include
#
gcc -c -Wall filum.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv filum.o ~/libc/filum.o
#
echo "Normal end of execution."
