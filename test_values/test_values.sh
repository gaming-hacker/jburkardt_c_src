#! /bin/bash
#
cp test_values.h /$HOME/include
#
gcc -c -Wall test_values.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_values.o ~/libc/test_values.o
#
echo "Normal end of execution."
