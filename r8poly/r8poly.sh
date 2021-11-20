#! /bin/bash
#
cp r8poly.h /$HOME/include
#
gcc -c -I/$HOME/include r8poly.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8poly.o ~/libc/r8poly.o
#
echo "Normal end of execution."
