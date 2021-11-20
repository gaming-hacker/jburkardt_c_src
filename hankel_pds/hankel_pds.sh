#! /bin/bash
#
cp hankel_pds.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include hankel_pds.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hankel_pds.o ~/libc/hankel_pds.o
#
echo "Normal end of execution."
