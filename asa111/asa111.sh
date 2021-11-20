#! /bin/bash
#
cp asa111.h /$HOME/include
#
gcc -c -Wall asa111.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa111.o ~/libc/asa111.o
#
echo "Normal end of execution."
