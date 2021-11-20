#! /bin/bash
#
gcc -c -Wall -I/$HOME/include disk01_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc disk01_rule_test.o /$HOME/libc/disk01_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm disk01_rule_test.o
#
mv a.out disk01_rule_test
./disk01_rule_test > disk01_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm disk01_rule_test
#
echo "Normal end of execution."
