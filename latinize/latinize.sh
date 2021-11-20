#! /bin/bash
#
cp latinize.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include latinize.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv latinize.o ~/libc/latinize.o
#
echo "Normal end of execution."
