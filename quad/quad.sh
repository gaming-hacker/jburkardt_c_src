#! /bin/bash
#
gcc -c -Wall quad.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o quad quad.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quad.o
#
mv quad $HOME/binc
#
echo "Normal end of execution."
