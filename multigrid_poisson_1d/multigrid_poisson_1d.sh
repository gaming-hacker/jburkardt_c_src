#! /bin/bash
#
cp multigrid_poisson_1d.h /$HOME/include
#
gcc -c -Wall multigrid_poisson_1d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv multigrid_poisson_1d.o ~/libc/multigrid_poisson_1d.o
#
echo "Normal end of execution."
