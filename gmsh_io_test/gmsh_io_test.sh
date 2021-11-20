#! /bin/bash
#
gcc -c -Wall -I/$HOME/include gmsh_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o gmsh_io_test gmsh_io_test.o /$HOME/libc/gmsh_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gmsh_io_test.o
#
./gmsh_io_test > gmsh_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm gmsh_io_test
#
echo "Normal end of execution."
