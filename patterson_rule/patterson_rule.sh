#! /bin/bash
#
gcc -c -Wall patterson_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc patterson_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm patterson_rule.o
#
chmod ugo+x a.out
mv a.out ~/binc/patterson_rule
#
echo "Normal end of execution."
