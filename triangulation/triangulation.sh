#! /bin/bash
#
cp triangulation.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include triangulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangulation.o ~/libc/triangulation.o
#
echo "Normal end of execution."
