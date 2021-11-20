#! /bin/bash
#
gcc -c -Wall -I/$HOME/include line_felippa_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc line_felippa_rule_test.o /$HOME/libc/line_felippa_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm line_felippa_rule_test.o
#
mv a.out line_felippa_rule_test
./line_felippa_rule_test > line_felippa_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_felippa_rule_test
#
echo "Normal end of execution."
