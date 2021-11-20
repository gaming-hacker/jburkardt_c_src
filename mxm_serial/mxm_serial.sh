#! /bin/bash
#
gcc -c -Wall -I/$HOME/include mxm_serial.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mxm_serial.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mxm_serial.o
#
mv a.out $HOME/binc/mxm_serial
#
echo "Normal end of execution."
