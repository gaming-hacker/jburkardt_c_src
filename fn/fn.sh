#! /bin/bash
#
cp fn.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fn.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fn.o ~/libc/fn.o
#
echo "Normal end of execution."
