#! /bin/bash
#
cp constants.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include constants.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv constants.o ~/libc/constants.o
#
echo "Normal end of execution."
