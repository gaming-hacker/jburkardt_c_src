#! /bin/bash
#
cp prime.h /$HOME/include
#
gcc -c -Wall prime.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv prime.o ~/libc/prime.o
#
echo "Normal end of execution."
