#! /bin/bash
#
gcc -c -Wall pres_temp_4D_wr.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pres_temp_4D_wr.o -L$HOME/lib -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pres_temp_4D_wr.o
#
mv a.out pres_temp_4D_wr
./pres_temp_4D_wr > pres_temp_4D_wr_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pres_temp_4D_wr
#
echo "Normal end of execution."
