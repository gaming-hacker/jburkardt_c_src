#! /bin/bash
#
cp sort_rc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include sort_rc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sort_rc.o ~/libc/sort_rc.o
#
echo "Normal end of execution."
