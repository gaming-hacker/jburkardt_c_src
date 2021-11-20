#! /bin/bash
#
gcc -c -Wall not_allocated_arrays.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc not_allocated_arrays.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm not_allocated_arrays.o
#
mv a.out not_allocated_arrays
./not_allocated_arrays > not_allocated_arrays.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm not_allocated_arrays
#
echo "Normal end of execution."
