#! /bin/bash
#
cp asa082.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include asa082.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa082.o ~/libc/asa082.o
#
echo "Normal end of execution."
