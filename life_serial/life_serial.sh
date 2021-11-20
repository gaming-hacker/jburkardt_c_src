#! /bin/bash
#
gcc -c -Wall life_serial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc life_serial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm life_serial.o
#
chmod ugo+x a.out
mv a.out ~/binc/life_serial
#
echo "Normal end of execution."
