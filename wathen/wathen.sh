#! /bin/bash
#
cp wathen.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include wathen.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wathen.o ~/libc/wathen.o
#
echo "Normal end of execution."
