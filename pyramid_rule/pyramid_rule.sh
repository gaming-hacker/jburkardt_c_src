#! /bin/bash
#
gcc -c -Wall pyramid_rule.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc pyramid_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm pyramid_rule.o
#
chmod ugo+x a.out
mv a.out ~/binc/pyramid_rule
#
echo "Normal end of execution."
