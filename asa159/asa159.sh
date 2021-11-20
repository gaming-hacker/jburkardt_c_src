#! /bin/bash
#
cp asa159.h /$HOME/include
#
gcc -c -Wall asa159.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa159.o ~/libc/asa159.o
#
echo "Normal end of execution."
