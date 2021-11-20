#! /bin/bash
#
cp owen.h /$HOME/include
#
gcc -c -Wall owen.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv owen.o ~/libc/owen.o
#
echo "Normal end of execution."
