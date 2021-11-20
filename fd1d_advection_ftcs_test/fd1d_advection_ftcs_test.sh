#! /bin/bash
#
$HOME/binc/fd1d_advection_ftcs > fd1d_advection_ftcs_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
