#! /bin/bash
#
cp toms179.h /$HOME/include
#
gcc -c -Wall toms179.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms179.o ~/libc/toms179.o
#
echo "Normal end of execution."
