#! /bin/bash
#
gcc -c -Wall -I/$HOME/include navier_stokes_3d_exact_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o navier_stokes_3d_exact_test navier_stokes_3d_exact_test.o /$HOME/libc/navier_stokes_3d_exact.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm navier_stokes_3d_exact_test.o
#
./navier_stokes_3d_exact_test > navier_stokes_3d_exact_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm navier_stokes_3d_exact_test
#
echo "Normal end of execution."
