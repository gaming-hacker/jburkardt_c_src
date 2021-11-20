#! /bin/bash
#
cp st_io.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include st_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv st_io.o ~/libc/st_io.o
#
echo "Normal end of execution."
