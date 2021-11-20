#! /bin/bash
#
gcc -c -Wall -I/$HOME/include csparse_test02.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c -Wall -I/$HOME/include csparse_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc csparse_test02.o csparse_test.o $HOME/libc/csparse.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm csparse_test02.o
rm csparse_test.o
#
chmod ugo+x a.out
mv a.out csparse_test02
#
./csparse_test02 < kershaw.st > csparse_test02.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm csparse_test02
#
echo "Normal end of execution."
