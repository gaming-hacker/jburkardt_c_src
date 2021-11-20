#! /bin/bash
#
gcc -c -Wall fire_serial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fire_serial.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fire_serial.o
#
mv a.out $HOME/binc/fire_serial
#
echo "Normal end of execution."
