#! /bin/bash
#
cp root_rc.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include root_rc.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv root_rc.o ~/libc/root_rc.o
#
echo "Normal end of execution."
