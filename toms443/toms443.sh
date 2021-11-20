#! /bin/bash
#
cp toms443.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include toms443.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms443.o ~/libc/toms443.o
#
echo "Normal end of execution."
