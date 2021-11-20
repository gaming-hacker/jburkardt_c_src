#! /bin/bash
#
gcc -c -Wall hermite_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hermite_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hermite_rule.o
#
chmod ugo+x a.out
mv a.out ~/binc/hermite_rule
#
echo "Normal end of execution."
