#! /bin/bash
#
gcc -c -Wall -g test03.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc test03.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out test03
echo "Executable created as test03"
#
#  Run program
#
./test03 > test03.txt
echo "Executable output stored as test03.txt"
#
#  Rerun program with valgrind
#
valgrind --dsymutil=yes ./test03 &> test03_valgrind.txt
echo "Valgrind output stored as test03_valgrind.txt"
#
#  Don't delete object code til later!
#
rm test03.o
rm test03
#
echo "Normal end of execution."
