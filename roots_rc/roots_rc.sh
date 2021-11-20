#! /bin/bash
#
cp roots_rc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include roots_rc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv roots_rc.o ~/libc/roots_rc.o
#
echo "Normal end of execution."
