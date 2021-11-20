#! /bin/bash
#
cp mgs.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include mgs.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv mgs.o ~/libc/mgs.o
#
echo "Normal end of execution."
