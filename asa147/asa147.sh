#! /bin/bash
#
cp asa147.h /$HOME/include
#
gcc -c -Wall asa147.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa147.o ~/libc/asa147.o
#
echo "Normal end of execution."
