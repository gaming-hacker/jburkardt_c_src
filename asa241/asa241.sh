#! /bin/bash
#
cp asa241.h /$HOME/include
#
gcc -c -Wall asa241.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa241.o ~/libc/asa241.o
#
echo "Normal end of execution."
