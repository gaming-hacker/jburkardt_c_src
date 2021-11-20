#! /bin/bash
#
cp ubvec.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include ubvec.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ubvec.o ~/libc/ubvec.o
#
echo "Normal end of execution."
