#! /bin/bash
#
gcc -c -Wall truncated_normal_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc truncated_normal_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm truncated_normal_rule.o
mv a.out ~/binc/truncated_normal_rule
#
echo "Normal end of execution."
