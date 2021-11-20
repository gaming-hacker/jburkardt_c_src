#! /bin/bash
#
cp gmsh_io.h /$HOME/include
#
gcc -c -Wall -I/$HOME/include gmsh_io.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv gmsh_io.o ~/libc/gmsh_io.o
#
echo "Normal end of execution."
