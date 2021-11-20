#! /bin/bash
#
cp subpak.h /$HOME/include
#
gcc -c -Wall subpak.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv subpak.o ~/libc/subpak.o
#
echo "Normal end of execution."
