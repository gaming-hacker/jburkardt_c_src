#! /bin/bash
#
gcc -c -Wall -I/$HOME/include triangle_nco_rule_test.c 
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc triangle_nco_rule_test.o /$HOME/libc/triangle_nco_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_nco_rule_test.o
#
mv a.out triangle_nco_rule_test
./triangle_nco_rule_test > triangle_nco_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_nco_rule_test
#
echo "Normal end of execution."
