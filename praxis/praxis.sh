#! /bin/bash
#
cp praxis.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include praxis.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv praxis.o ~/libc/praxis.o
#
echo "Normal end of execution."
