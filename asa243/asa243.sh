#! /bin/bash
#
cp asa243.h /$HOME/include
#
gcc -c -Wall asa243.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa243.o ~/libc/asa243.o
#
echo "Normal end of execution."
