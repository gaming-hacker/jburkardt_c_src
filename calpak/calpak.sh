#! /bin/bash
#
cp calpak.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include calpak.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv calpak.o ~/libc/calpak.o
#
echo "Normal end of execution."
