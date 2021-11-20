#! /bin/bash
#
gcc -c -Wall -I/$HOME/include freefem_msh_io_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o freefem_msh_io_test freefem_msh_io_test.o /$HOME/libc/freefem_msh_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm freefem_msh_io_test.o
#
./freefem_msh_io_test > freefem_msh_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm freefem_msh_io_test
#
echo "Normal end of execution."
