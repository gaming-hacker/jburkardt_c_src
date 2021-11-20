#! /bin/bash
#
$HOME/binc/md 3 500 500 0.1 > md_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
