#! /bin/bash
#
gcc -c -Wall fd1d_burgers_lax.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd1d_burgers_lax.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fd1d_burgers_lax.o
#
mv a.out ~/binc/fd1d_burgers_lax
#
echo "Normal end of execution."
