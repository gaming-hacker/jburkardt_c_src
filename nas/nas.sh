#! /bin/bash
#
gcc -c -Wall nas.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o nas nas.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm nas.o
#
mv nas $HOME/binc/nas
#
echo "Normal end of execution."
