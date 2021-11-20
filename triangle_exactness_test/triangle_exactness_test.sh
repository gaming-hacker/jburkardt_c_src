#! /bin/bash
#
$HOME/binc/triangle_exactness < input.txt > triangle_exactness_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

