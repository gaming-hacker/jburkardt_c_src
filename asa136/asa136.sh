#! /bin/bash
#
cp asa136.h /$HOME/include
#
gcc -c -Wall asa136.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa136.o ~/libc/asa136.o
#
echo "Normal end of execution."
