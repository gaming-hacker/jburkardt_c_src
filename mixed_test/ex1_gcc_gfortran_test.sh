#! /bin/bash
#
gcc -c -Wall ex1_main.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gfortran -c -Wall -fno-underscoring ex1_sub.f90
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Use the GCC program to load.
#  In some cases, the FORTRAN libraries may need to be included,
#  using an argument like "-lfor".
#  The C math libraries may need to be included, with "-lm".
#
gcc ex1_main.o ex1_sub.o -lgfortran -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out ex1_gcc_gfortran
rm *.o
#
#  Run the program.
#
./ex1_gcc_gfortran > ex1_gcc_gfortran_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ex1_gcc_gfortran
#
echo "Normal end of execution."
