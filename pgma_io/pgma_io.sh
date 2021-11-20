#! /bin/bash
#
cp pgma_io.h /$HOME/include
#
gcc -c -Wall pgma_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pgma_io.o ~/libc/pgma_io.o
#
echo "Normal end of execution."
