#! /bin/bash
#
gcc -c -Wall -O1 md.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc md.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm md.o
#
mv a.out md_O1
./md_O1 < md_input.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm md_O1
#
echo "Normal end of execution."
