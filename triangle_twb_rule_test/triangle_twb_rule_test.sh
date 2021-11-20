#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_twb_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_twb_rule_test.o /$HOME/libc/triangle_twb_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_twb_rule_test.o
#
mv a.out triangle_twb_rule_test
./triangle_twb_rule_test > triangle_twb_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_twb_rule_test
#
echo "Normal end of execution."
