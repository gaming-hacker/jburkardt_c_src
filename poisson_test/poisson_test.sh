#! /bin/bash
#
$HOME/binc/poisson > poisson_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
