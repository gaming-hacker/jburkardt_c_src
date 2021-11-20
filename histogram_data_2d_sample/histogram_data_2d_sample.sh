#! /bin/bash
#
gcc -c -Wall histogram_data_2d_sample.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc histogram_data_2d_sample.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm histogram_data_2d_sample.o
#
mv a.out ~/binc/histogram_data_2d_sample
#
echo "Normal end of execution."
