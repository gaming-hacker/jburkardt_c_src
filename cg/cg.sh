#! /bin/bash
#
cp cg.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include cg.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cg.o ~/libc/cg.o
#
echo "Normal end of execution."
