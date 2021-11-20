#! /bin/bash
#
cp condition.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include condition.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv condition.o ~/libc/condition.o
#
echo "Normal end of execution."
