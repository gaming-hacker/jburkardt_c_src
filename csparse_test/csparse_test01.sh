#! /bin/bash
#
gcc -c -Wall -I/$HOME/include csparse_test01.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc csparse_test01.o $HOME/libc/csparse.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm csparse_test01.o
#
chmod ugo+x a.out
mv a.out csparse_test01
#
./csparse_test01 < kershaw.st > csparse_test01.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm csparse_test01
#
echo "Normal end of execution."
