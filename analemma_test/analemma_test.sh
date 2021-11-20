#! /bin/bash
#
~/binc/analemma -e 0.01671 -l 1.347 -o 0.4091 > analemma_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
gnuplot analemma_commands.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
