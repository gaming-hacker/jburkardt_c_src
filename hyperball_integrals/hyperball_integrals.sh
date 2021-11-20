#! /bin/bash
#
cp hyperball_integrals.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include hyperball_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hyperball_integrals.o ~/libc/hyperball_integrals.o
#
echo "Normal end of execution."
