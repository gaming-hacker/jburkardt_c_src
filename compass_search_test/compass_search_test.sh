#! /bin/bash
#
gcc -c -Wall -I/$HOME/include compass_search_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc compass_search_test.o /$HOME/libc/compass_search.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm compass_search_test.o
#
mv a.out compass_search_test
./compass_search_test > compass_search_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm compass_search_test
#
echo "Normal end of execution."
