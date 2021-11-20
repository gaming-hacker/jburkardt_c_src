#! /bin/bash
#
cp asa113.h /$HOME/include
#
gcc -c -Wall asa113.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa113.o ~/libc/asa113.o
#
echo "Normal end of execution."
