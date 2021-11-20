#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sandia_rules_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sandia_rules_test.o /$HOME/libc/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sandia_rules_test.o
#
mv a.out sandia_rules_test
./sandia_rules_test > sandia_rules_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sandia_rules_test
#
echo "Normal end of execution."
