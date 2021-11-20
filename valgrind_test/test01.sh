#! /bin/bash
#
gcc -c -g -Wall test01.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test01.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out test01
echo "Executable created as test01"
#
#  Run program
#
./test01 > test01.txt
echo "Executable output stored as test01.txt"
#
#  Rerun program with valgrind
#
valgrind --dsymutil=yes ./test01 &> test01_valgrind.txt
echo "Valgrind output stored as test01_valgrind.txt"
#
#  Don't delete object code til later!
#
rm test01.o
rm test01
#
echo "Normal end of execution."
