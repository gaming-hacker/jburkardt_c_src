#! /bin/bash
#
gcc -c -Wall -I$HOME/include alpert_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o alpert_rule_test alpert_rule_test.o -L$HOME/libc -lalpert_rule -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm alpert_rule_test.o
#
./alpert_rule_test > alpert_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm alpert_rule_test
#
echo "Normal end of execution."
