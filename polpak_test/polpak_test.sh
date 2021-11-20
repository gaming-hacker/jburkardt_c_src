#! /bin/bash
#
gcc -c -Wall -I/$HOME/include polpak_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc polpak_test.o /$HOME/libc/polpak.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polpak_test.o
#
mv a.out polpak_test
./polpak_test > polpak_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polpak_test
#
echo "Normal end of execution."
