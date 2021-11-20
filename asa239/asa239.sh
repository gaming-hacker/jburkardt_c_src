#! /bin/bash
#
cp asa239.h /$HOME/include
#
gcc -c -Wall asa239.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa239.o ~/libc/asa239.o
#
echo "Normal end of execution."
