#! /bin/bash
#
gcc -c -Wall md.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o md md.o -lm
if [ $? -ne 0 ]; then
  echo "Load error"
  exit
fi
#
rm md.o
mv md $HOME/binc/md
#
echo "Normal end of execution."
