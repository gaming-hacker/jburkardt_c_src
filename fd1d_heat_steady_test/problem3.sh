#! /bin/bash
#
gcc -c -Wall -I$HOME/include problem3.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc problem3.o $HOME/libc/fd1d_heat_steady.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm problem3.o
#
mv a.out problem3
./problem3 > problem3.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem3
#
echo "Normal end of execution."
