#! /bin/bash
#
cp wishart.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include wishart.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wishart.o ~/libc/wishart.o
#
echo "Normal end of execution."
