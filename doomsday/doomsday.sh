#! /bin/bash
#
cp doomsday.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include doomsday.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv doomsday.o ~/libc/doomsday.o
#
echo "Normal end of execution."
