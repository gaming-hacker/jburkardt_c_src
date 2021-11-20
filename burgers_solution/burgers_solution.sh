#! /bin/bash
#
cp burgers_solution.h /$HOME/include
#
gcc -c -Wall burgers_solution.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv burgers_solution.o ~/libc/burgers_solution.o
#
echo "Normal end of execution."
