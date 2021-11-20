#! /bin/bash
#
cp exactness.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include exactness.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv exactness.o ~/libc/exactness.o
#
echo "Normal end of execution."
