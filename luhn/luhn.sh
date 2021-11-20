#! /bin/bash
#
cp luhn.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include luhn.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv luhn.o ~/libc/luhn.o
#
echo "Normal end of execution."
