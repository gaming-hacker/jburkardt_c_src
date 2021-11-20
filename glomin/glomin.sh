#! /bin/bash
#
cp glomin.h /$HOME/include
#
gcc -c -Wall glomin.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv glomin.o ~/libc/glomin.o
#
echo "Normal end of execution."
