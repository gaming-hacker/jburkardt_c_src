#! /bin/bash
#
cp polpak.h /$HOME/include
#
gcc -c -Wall polpak.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polpak.o ~/libc/polpak.o
#
echo "Normal end of execution."
