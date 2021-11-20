#! /bin/bash
#
gcc -c -Wall damped_sine.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc damped_sine.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm damped_sine.o
mv a.out ~/binc/damped_sine
#
echo "Normal end of execution."
