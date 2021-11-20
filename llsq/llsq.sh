#! /bin/bash
#
cp llsq.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include llsq.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv llsq.o ~/libc/llsq.o
#
echo "Normal end of execution."
