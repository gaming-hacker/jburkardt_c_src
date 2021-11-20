#! /bin/bash
#
cp jacobi_eigenvalue.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include jacobi_eigenvalue.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv jacobi_eigenvalue.o ~/libc/jacobi_eigenvalue.o
#
echo "Normal end of execution."
