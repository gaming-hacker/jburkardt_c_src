#! /bin/bash
#
gcc -c -Wall -I/$HOME/include csparse_test03.c
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
gcc csparse_test03.o csparse_test.o $HOME/libc/csparse.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm csparse_test03.o
rm csparse_test.o
#
chmod ugo+x a.out
mv a.out csparse_test03
#
./csparse_test03 < kershaw.st > csparse_test03.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm csparse_test03
#
echo "Normal end of execution."
