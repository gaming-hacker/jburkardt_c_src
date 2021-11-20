#! /bin/bash
#
cp asa152.h /$HOME/include
#
gcc -c -Wall asa152.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa152.o ~/libc/asa152.o
#
echo "Normal end of execution."
