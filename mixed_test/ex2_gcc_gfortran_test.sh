#! /bin/bash
#
gcc -c -Wall ex2_main.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gfortran -c -Wall -fno-underscoring ex2_sub.f90
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
gcc ex2_main.o ex2_sub.o -lgfortran -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out ex2_gcc_gfortran
rm *.o
#
#  Run the program.
#
./ex2_gcc_gfortran > ex2_gcc_gfortran_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ex2_gcc_gfortran
#
echo "Normal end of execution."
