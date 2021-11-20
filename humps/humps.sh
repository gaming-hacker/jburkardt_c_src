#! /bin/bash
#
cp humps.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include humps.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv humps.o ~/libc/humps.o
#
echo "Normal end of execution."
