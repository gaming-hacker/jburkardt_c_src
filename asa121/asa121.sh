#! /bin/bash
#
cp asa121.h /$HOME/include
#
gcc -c -Wall asa121.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa121.o ~/libc/asa121.o
#
echo "Normal end of execution."
