#! /bin/bash
#
cp asa310.h /$HOME/include
#
gcc -c -Wall asa310.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa310.o ~/libc/asa310.o
#
echo "Normal end of execution."
