#! /bin/bash
#
cp abc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include abc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv abc.o ~/libc/abc.o
#
echo "Normal end of execution."
