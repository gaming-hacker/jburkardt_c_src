#! /bin/bash
#
cp disk01_integrals.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include disk01_integrals.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk01_integrals.o ~/libc
#
echo "Normal end of execution."
