#! /bin/bash
#
cp walker_sample.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include walker_sample.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv walker_sample.o ~/libc/walker_sample.o
#
echo "Normal end of execution."
