#! /bin/bash
#
gcc -c -Wall search.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o search search.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm search.o
#
mv search $HOME/binc
#
echo "Normal end of execution."
