#! /bin/bash
#
gcc -c -Wall pig_latin.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pig_latin.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pig_latin.o
mv a.out ~/binc/pig_latin
#
echo "Normal end of execution."
