#! /bin/bash
#
cp toms655.h /$HOME/include
#
gcc -c -Wall toms655.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms655.o ~/libc/toms655.o
#
echo "Normal end of execution."
