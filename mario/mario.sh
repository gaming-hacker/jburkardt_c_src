#! /bin/bash
#
gcc -c -Wall mario.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o mario mario.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mario.o
#
mv mario $HOME/binc/mario
#
echo "Normal end of execution."
