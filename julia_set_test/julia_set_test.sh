#! /bin/bash
#
$HOME/binc/julia_set > julia_set_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

