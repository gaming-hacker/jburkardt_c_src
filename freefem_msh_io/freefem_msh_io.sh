#! /bin/bash
#
cp freefem_msh_io.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include freefem_msh_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv freefem_msh_io.o ~/libc/freefem_msh_io.o
#
echo "Normal end of execution."
