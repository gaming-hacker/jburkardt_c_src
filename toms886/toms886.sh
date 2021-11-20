#! /bin/bash
#
cp toms886.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include toms886.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms886.o ~/libc/toms886.o
#
echo "Normal end of execution."
