#! /bin/bash
#
gcc -c -Wall -I/$HOME/include tetrahedron_keast_rule_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc tetrahedron_keast_rule_test.o /$HOME/libc/tetrahedron_keast_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tetrahedron_keast_rule_test.o
#
mv a.out tetrahedron_keast_rule_test
./tetrahedron_keast_rule_test > tetrahedron_keast_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tetrahedron_keast_rule_test
#
echo "Normal end of execution."
