#! /bin/bash
#
cp asa245.h /$HOME/include
#
gcc -c -Wall asa245.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa245.o ~/libc/asa245.o
#
echo "Normal end of execution."
