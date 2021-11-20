#! /bin/bash
#
cp index.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include index.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv index.o ~/libc/index.o
#
echo "Normal end of execution."
