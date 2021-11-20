#! /bin/bash
#
gcc -c -Wall string_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o string_simulation string_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm string_simulation.o
#
mv string_simulation $HOME/binc 
#
echo "Normal end of execution."
