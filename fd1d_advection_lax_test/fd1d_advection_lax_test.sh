#! /bin/bash
#
$HOME/binc/fd1d_advection_lax > fd1d_advection_lax_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
