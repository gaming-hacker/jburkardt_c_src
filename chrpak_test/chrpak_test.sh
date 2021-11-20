#! /bin/bash
#
gcc -c -Wall -I/$HOME/include chrpak_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc chrpak_test.o /$HOME/libc/chrpak.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm chrpak_test.o
#
mv a.out chrpak_test
./chrpak_test > chrpak_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm chrpak_test
#
echo "Normal end of execution."
