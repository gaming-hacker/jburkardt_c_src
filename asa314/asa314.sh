#! /bin/bash
#
cp asa314.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include asa314.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa314.o ~/libc/asa314.o
#
echo "Normal end of execution."
