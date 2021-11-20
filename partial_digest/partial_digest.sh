#! /bin/bash
#
cp partial_digest.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include partial_digest.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv partial_digest.o ~/libc/partial_digest.o
#
echo "Normal end of execution."
