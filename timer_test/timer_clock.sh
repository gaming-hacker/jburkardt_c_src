#! /bin/bash
#
gcc -c -Wall timer_clock.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o timer_clock timer_clock.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm timer_clock.o
#
./timer_clock > timer_clock.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm timer_clock
#
echo "Normal end of execution."
