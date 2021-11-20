#! /bin/bash
#
cp fem1d_pack.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include fem1d_pack.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv fem1d_pack.o ~/libc/fem1d_pack.o
#
echo "Normal end of execution."
