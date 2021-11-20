#! /bin/bash
#
cp edge.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include edge.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv edge.o ~/libc/edge.o
#
echo "Normal end of execution."
