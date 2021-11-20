#! /bin/bash
#
cp differ.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include differ.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv differ.o ~/libc/differ.o
#
echo "Normal end of execution."
