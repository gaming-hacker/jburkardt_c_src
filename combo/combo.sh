#! /bin/bash
#
cp combo.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include combo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv combo.o ~/libc/combo.o
#
echo "Normal end of execution."
