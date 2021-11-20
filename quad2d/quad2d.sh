#! /bin/bash
#
gcc -c -Wall quad2d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o quad2d quad2d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quad2d.o
#
mv quad2d $HOME/binc
#
echo "Normal end of execution."
