#! /bin/bash
#
cp latin_cover.h /$HOME/include
#
gcc -c -Wall latin_cover.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv latin_cover.o ~/libc/latin_cover.o
#
echo "Normal end of execution."
