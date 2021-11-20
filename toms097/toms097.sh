#! /bin/bash
#
cp toms097.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include toms097.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms097.o ~/libc/toms097.o
#
echo "Normal end of execution."
