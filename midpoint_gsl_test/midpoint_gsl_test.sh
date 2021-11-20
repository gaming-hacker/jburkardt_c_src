#! /bin/bash
#
gcc -c -Wall midpoint_gsl_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc midpoint_gsl_test.o -lm -lgsl -lgslcblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm midpoint_gsl_test.o
#
mv a.out midpoint_gsl_test
./midpoint_gsl_test > midpoint_gsl_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm midpoint_gsl_test
#
#  Plot the data.
#
gnuplot < gnuplot_commands.txt
#
echo "Normal end of execution."
