#! /bin/bash
#
cp sftpack.h /$HOME/include
#
gcc -c -Wall sftpack.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sftpack.o ~/libc/sftpack.o
#
echo "Normal end of execution."
