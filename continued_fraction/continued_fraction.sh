#! /bin/bash
#
cp continued_fraction.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include continued_fraction.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv continued_fraction.o ~/libc/continued_fraction.o
#
echo "Normal end of execution."
