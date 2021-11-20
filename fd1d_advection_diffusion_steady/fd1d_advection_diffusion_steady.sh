#! /bin/bash
#
gcc -c -Wall fd1d_advection_diffusion_steady.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fd1d_advection_diffusion_steady.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fd1d_advection_diffusion_steady.o
mv a.out ~/binc/fd1d_advection_diffusion_steady
#
echo "Normal end of execution."
