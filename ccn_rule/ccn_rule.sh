#! /bin/bash
#
gcc -c -Wall ccn_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc ccn_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ccn_rule.o
#
chmod ugo+x a.out
mv a.out ~/binc/ccn_rule
#
echo "Normal end of execution."
