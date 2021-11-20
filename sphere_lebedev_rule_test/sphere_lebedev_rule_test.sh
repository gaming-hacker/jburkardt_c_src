#! /bin/bash
#
gcc -c -Wall -I /$HOME/include sphere_lebedev_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sphere_lebedev_rule_test.o /$HOME/libc/sphere_lebedev_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm sphere_lebedev_rule_test.o
#
mv a.out sphere_lebedev_rule_test
./sphere_lebedev_rule_test > sphere_lebedev_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_lebedev_rule_test
#
echo "Normal end of execution."
