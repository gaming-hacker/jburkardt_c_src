#! /bin/bash
#
$HOME/binc/f77split f77split_test.f > f77split_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
