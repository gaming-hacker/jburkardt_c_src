#! /bin/bash
#
gcc -c -Wall sfc_pres_temp_rd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sfc_pres_temp_rd.o -L$HOME/lib -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sfc_pres_temp_rd.o
#
mv a.out sfc_pres_temp_rd
./sfc_pres_temp_rd > sfc_pres_temp_rd_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sfc_pres_temp_rd
#
echo "Normal end of execution."
