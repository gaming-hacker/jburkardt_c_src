#! /bin/bash
#
$HOME/binc/quad2d > quad2d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

