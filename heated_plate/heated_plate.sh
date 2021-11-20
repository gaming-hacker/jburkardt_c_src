#! /bin/bash
#
gcc -c -Wall heated_plate.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc heated_plate.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm heated_plate.o
mv a.out ~/binc/heated_plate
#
echo "Normal end of execution."
