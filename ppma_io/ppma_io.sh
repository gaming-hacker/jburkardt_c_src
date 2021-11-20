#! /bin/bash
#
cp ppma_io.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include ppma_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ppma_io.o ~/libc/ppma_io.o
#
echo "Normal end of execution."
