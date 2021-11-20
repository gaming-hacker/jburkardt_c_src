#! /bin/bash
#
gcc -c -Wall simple_xy_rd.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc simple_xy_rd.o -L$HOME/lib -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simple_xy_rd.o
#
mv a.out simple_xy_rd
./simple_xy_rd > simple_xy_rd_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simple_xy_rd
#
echo "Normal end of execution."
