#! /bin/bash
#
cp floyd.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include floyd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv floyd.o ~/libc/floyd.o
#
echo "Normal end of execution."
