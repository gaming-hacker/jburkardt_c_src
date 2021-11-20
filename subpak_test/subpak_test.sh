#! /bin/bash
#
gcc -c -Wall -I/$HOME/include subpak_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc subpak_test.o /$HOME/libc/subpak.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm subpak_test.o
#
mv a.out subpak_test
./subpak_test > subpak_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm subpak_test
#
echo "Normal end of execution."
