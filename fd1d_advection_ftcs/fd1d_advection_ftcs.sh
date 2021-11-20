#! /bin/bash
#
gcc -c -Wall fd1d_advection_ftcs.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd1d_advection_ftcs.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fd1d_advection_ftcs.o
mv a.out ~/binc/fd1d_advection_ftcs
#
echo "Normal end of execution."
