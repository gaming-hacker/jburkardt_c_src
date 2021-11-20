#! /bin/bash
#
gcc -c -Wall -I$HOME/include ellipse.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ellipse.o $HOME/libc/toms886.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ellipse.o
#
mv a.out ellipse
./ellipse > ellipse.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ellipse
#
echo "Normal end of execution."
