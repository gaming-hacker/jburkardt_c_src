#! /bin/bash
#
~/binc/args Fred 1 8.3 > args_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
