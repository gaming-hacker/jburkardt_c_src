#! /bin/bash
#
gcc -c -I/$HOME/include annulus_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o annulus_rule_test annulus_rule_test.o -L/$HOME/libc -lannulus_rule -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm annulus_rule_test.o
#
./annulus_rule_test > annulus_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm annulus_rule_test
#
echo "Normal end of execution."
