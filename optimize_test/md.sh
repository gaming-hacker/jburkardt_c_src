#! /bin/bash
#
gcc -c -Wall md.c
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
mv a.out md
./md < md_input.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm md
#
echo "Normal end of execution."
