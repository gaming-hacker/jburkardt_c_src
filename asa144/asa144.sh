#! /bin/bash
#
cp asa144.h /$HOME/include
#
gcc -c -Wall asa144.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa144.o ~/libc/asa144.o
#
echo "Normal end of execution."
