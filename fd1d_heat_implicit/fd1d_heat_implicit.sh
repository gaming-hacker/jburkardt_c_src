#! /bin/bash
#
gcc -c -Wall fd1d_heat_implicit.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd1d_heat_implicit.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fd1d_heat_implicit.o
#
mv a.out ~/binc/fd1d_heat_implicit
#
echo "Normal end of execution."
