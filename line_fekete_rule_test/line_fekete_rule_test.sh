#! /bin/bash
#
gcc -c -Wall -I/$HOME/include line_fekete_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc line_fekete_rule_test.o /$HOME/libc/line_fekete_rule.o \
                           /$HOME/libc/qr_solve.o \
                           /$HOME/libc/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm line_fekete_rule_test.o
#
mv a.out line_fekete_rule_test
./line_fekete_rule_test > line_fekete_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_fekete_rule_test
#
echo "Normal end of execution."
