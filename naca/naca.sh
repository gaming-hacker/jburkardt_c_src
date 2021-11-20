#! /bin/bash
#
cp naca.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include naca.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv naca.o ~/libc/naca.o
#
echo "Normal end of execution."
