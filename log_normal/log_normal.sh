#! /bin/bash
#
cp log_normal.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include log_normal.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv log_normal.o ~/libc/log_normal.o
#
echo "Normal end of execution."
