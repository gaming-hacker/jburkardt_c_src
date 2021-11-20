#! /bin/bash
#
cp rkf45.h /$HOME/include
#
gcc -c -Wall rkf45.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rkf45.o ~/libc/rkf45.o
#
echo "Normal end of execution."
