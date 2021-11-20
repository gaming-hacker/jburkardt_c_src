#! /bin/bash
#
cp sine_transform.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include sine_transform.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sine_transform.o ~/libc/sine_transform.o
#
echo "Normal end of execution."
