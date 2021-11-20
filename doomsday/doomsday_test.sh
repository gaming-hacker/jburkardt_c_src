#! /bin/bash
#
gcc -c -Wall -I/$HOME/include doomsday_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc doomsday_test.o /$HOME/libc/doomsday.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm doomsday_test.o
#
mv a.out doomsday_test
./doomsday_test > doomsday_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm doomsday_test
#
echo "Normal end of execution."
