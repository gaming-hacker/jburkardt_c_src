#! /bin/bash
#
cp chrpak.h /$HOME/include
#
gcc -c -Wall chrpak.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chrpak.o ~/libc/chrpak.o
#
echo "Normal end of execution."
