#! /bin/bash
#
$HOME/binc/peri1d > peri1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

