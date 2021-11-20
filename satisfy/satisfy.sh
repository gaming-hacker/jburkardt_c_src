#! /bin/bash
#
gcc -c -Wall satisfy.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o satisfy satisfy.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm satisfy.o
#
mv satisfy $HOME/binc/satisfy
#
echo "Normal end of execution."
