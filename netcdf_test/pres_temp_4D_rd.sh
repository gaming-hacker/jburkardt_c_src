#! /bin/bash
#
gcc -c -Wall pres_temp_4D_rd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pres_temp_4D_rd.o -L$HOME/lib -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pres_temp_4D_rd.o
#
mv a.out pres_temp_4D_rd
./pres_temp_4D_rd > pres_temp_4D_rd_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pres_temp_4D_rd
#
echo "Normal end of execution."
