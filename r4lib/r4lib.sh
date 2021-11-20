#! /bin/bash
#
cp r4lib.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include r4lib.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r4lib.o ~/libc/r4lib.o
#
echo "Normal end of execution."
