#! /bin/bash
#
cp random_data.h /$HOME/include
#
gcc -c -Wall random_data.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv random_data.o ~/libc/random_data.o
#
echo "Normal end of execution."
