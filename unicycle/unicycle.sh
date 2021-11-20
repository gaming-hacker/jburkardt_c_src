#! /bin/bash
#
cp unicycle.h /$HOME/include
#
gcc -c -Wall unicycle.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv unicycle.o ~/libc/unicycle.o
#
echo "Normal end of execution."
