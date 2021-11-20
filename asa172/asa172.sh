#! /bin/bash
#
cp asa172.h /$HOME/include
#
gcc -c -Wall asa172.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa172.o ~/libc/asa172.o
#
echo "Normal end of execution."
