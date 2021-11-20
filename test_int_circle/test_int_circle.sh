#! /bin/bash
#
cp test_int_circle.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include test_int_circle.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_int_circle.o ~/libc/test_int_circle.o
#
echo "Normal end of execution."
