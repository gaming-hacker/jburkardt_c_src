#! /bin/bash
#
$HOME/binc/f90split f90split_test.f90 > f90split_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
