#! /bin/bash
#
cp test_int.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include test_int.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_int.o ~/libc/test_int.o
#
echo "Normal end of execution."
