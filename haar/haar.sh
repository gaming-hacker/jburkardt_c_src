#! /bin/bash
#
cp haar.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include haar.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv haar.o ~/libc/haar.o
#
echo "Normal end of execution."
