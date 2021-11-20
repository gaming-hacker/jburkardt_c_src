#! /bin/bash
#
cp asa226.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include asa226.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa226.o ~/libc/asa226.o
#
echo "Normal end of execution."
