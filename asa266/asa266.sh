#! /bin/bash
#
cp asa266.h /$HOME/include
#
gcc -c -Wall asa266.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa266.o ~/libc/asa266.o
#
echo "Normal end of execution."
