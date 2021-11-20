#! /bin/bash
#
cp fem_io.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fem_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem_io.o ~/libc/fem_io.o
#
echo "Normal end of execution."
