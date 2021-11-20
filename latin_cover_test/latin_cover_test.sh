#! /bin/bash
#
gcc -c -Wall -I/$HOME/include latin_cover_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc latin_cover_test.o /$HOME/libc/latin_cover.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm latin_cover_test.o
#
mv a.out latin_cover_test
./latin_cover_test > latin_cover_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm latin_cover_test
#
echo "Normal end of execution."
