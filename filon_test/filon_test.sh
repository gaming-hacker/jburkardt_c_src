#! /bin/bash
#
gcc -c -Wall -I/$HOME/include filon_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc filon_test.o /$HOME/libc/filon.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm filon_test.o
#
mv a.out filon_test
./filon_test > filon_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm filon_test
#
echo "Normal end of execution."
