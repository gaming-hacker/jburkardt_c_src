#! /bin/bash
#
gcc -c -Wall legendre_rule_fast.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc legendre_rule_fast.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm legendre_rule_fast.o
#
mv a.out ~/binc/legendre_rule_fast
#
echo "Normal end of execution."
