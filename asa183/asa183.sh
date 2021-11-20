#! /bin/bash
#
cp asa183.h /$HOME/include
#
gcc -c -Wall asa183.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa183.o ~/libc/asa183.o
#
echo "Normal end of execution."
