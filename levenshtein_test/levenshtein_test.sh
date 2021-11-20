#! /bin/bash
#
gcc -o levenshtein_test /$HOME/libc/levenshtein.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
./levenshtein_test > levenshtein_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm levenshtein_test
#
echo "Normal end of execution."
