#! /bin/bash
#
cp toms243.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include toms243.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms243.o ~/libc/toms243.o
#
echo "Normal end of execution."
