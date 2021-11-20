#! /bin/bash
#
gcc -c -Wall clenshaw_curtis_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc clenshaw_curtis_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm clenshaw_curtis_rule.o
#
chmod ugo+x a.out
mv a.out ~/binc/clenshaw_curtis_rule
#
echo "Normal end of execution."
