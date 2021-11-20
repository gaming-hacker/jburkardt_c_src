#! /bin/bash
#
cp weekday.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include weekday.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv weekday.o ~/libc/weekday.o
#
echo "Normal end of execution."
