#! /bin/bash
#
gcc -c -Wall shallow_water_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o shallow_water_1d shallow_water_1d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm shallow_water_1d.o
#
mv shallow_water_1d $HOME/binc
#
echo "Normal end of execution."
