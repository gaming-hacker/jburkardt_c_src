#! /bin/bash
#
gcc -c -Wall laguerre_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc laguerre_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm laguerre_rule.o
#
chmod ugo+x a.out
mv a.out ~/binc/laguerre_rule
#
echo "Normal end of execution."
