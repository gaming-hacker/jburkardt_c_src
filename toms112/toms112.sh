#! /bin/bash
#
cp toms112.h /$HOME/include
#
gcc -c -Wall toms112.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms112.o ~/libc/toms112.o
#
echo "Normal end of execution."
