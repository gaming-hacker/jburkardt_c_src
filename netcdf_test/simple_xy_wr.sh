#! /bin/bash
#
gcc -c -Wall simple_xy_wr.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc simple_xy_wr.o -L$HOME/lib -lnetcdf -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simple_xy_wr.o
#
mv a.out simple_xy_wr
./simple_xy_wr > simple_xy_wr_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simple_xy_wr
#
echo "Normal end of execution."
