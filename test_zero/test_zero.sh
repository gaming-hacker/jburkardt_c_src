#! /bin/bash
#
cp test_zero.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_zero.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_zero.o ~/libc/test_zero.o
#
echo "Normal end of execution."
