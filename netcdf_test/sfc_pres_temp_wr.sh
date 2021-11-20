#! /bin/bash
#
gcc -c -Wall sfc_pres_temp_wr.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sfc_pres_temp_wr.o -L$HOME/lib -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sfc_pres_temp_wr.o
#
mv a.out sfc_pres_temp_wr
./sfc_pres_temp_wr > sfc_pres_temp_wr_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sfc_pres_temp_wr
#
echo "Normal end of execution."
