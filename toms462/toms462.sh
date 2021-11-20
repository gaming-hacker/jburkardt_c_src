#! /bin/bash
#
cp toms462.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include toms462.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms462.o ~/libc/toms462.o
#
echo "Normal end of execution."
