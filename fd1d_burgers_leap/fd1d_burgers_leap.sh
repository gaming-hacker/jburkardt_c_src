#! /bin/bash
#
gcc -c -Wall fd1d_burgers_leap.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd1d_burgers_leap.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fd1d_burgers_leap.o
#
mv a.out ~/binc/fd1d_burgers_leap
#
echo "Normal end of execution."
