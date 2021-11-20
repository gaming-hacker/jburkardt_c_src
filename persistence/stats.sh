#! /bin/bash
#
cp stats.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include stats.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv stats.o ~/libc/stats.o
#
echo "Normal end of execution."
