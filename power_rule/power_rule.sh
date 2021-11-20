#! /bin/bash
#
gcc -c -Wall -I$HOME/include power_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc power_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm power_rule.o
#
chmod ugo+x a.out
mv a.out ~/binc/power_rule
#
echo "Normal end of execution."
