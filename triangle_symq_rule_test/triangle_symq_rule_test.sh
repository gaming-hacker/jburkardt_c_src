#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_symq_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o triangle_symq_rule_test triangle_symq_rule_test.o /$HOME/libc/triangle_symq_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_symq_rule_test.o
#
./triangle_symq_rule_test > triangle_symq_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_symq_rule_test
#
echo "Normal end of execution."
