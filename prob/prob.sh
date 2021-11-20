#! /bin/bash
#
cp prob.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include prob.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv prob.o ~/libc/prob.o
#
echo "Normal end of execution."
