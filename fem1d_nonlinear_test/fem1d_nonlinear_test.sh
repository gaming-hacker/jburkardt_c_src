#! /bin/bash
#
$HOME/binc/fem1d_nonlinear 1 > fem1d_nonlinear_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
$HOME/binc/fem1d_nonlinear 2 >> fem1d_nonlinear_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

