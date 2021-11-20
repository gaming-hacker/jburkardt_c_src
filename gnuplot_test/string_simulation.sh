#! /bin/bash
#
gcc -c -Wall string_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc string_simulation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm string_simulation.o
mv a.out ~/binc/string_simulation
#
echo "Normal end of execution."
