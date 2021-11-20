#! /bin/bash
#
gcc -c -Wall fd1d_advection_lax_wendroff.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd1d_advection_lax_wendroff.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fd1d_advection_lax_wendroff.o
mv a.out ~/binc/fd1d_advection_lax_wendroff
#
echo "Normal end of execution."
