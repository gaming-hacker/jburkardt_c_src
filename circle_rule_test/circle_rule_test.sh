#! /bin/bash
#
gcc -c -Wall -I/$HOME/include circle_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc circle_rule_test.o /$HOME/libc/circle_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm circle_rule_test.o
#
mv a.out circle_rule_test
./circle_rule_test > circle_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm circle_rule_test
#
echo "Normal end of execution."
