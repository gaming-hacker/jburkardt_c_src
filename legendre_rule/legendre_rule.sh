#! /bin/bash
#
gcc -c -Wall legendre_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc legendre_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm legendre_rule.o
#
chmod ugo+x a.out
mv a.out ~/binc/legendre_rule
#
echo "Normal end of execution."
