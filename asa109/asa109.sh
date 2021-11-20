#! /bin/bash
#
cp asa109.h /$HOME/include
#
gcc -c -Wall asa109.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa109.o ~/libc/asa109.o
#
echo "Normal end of execution."
