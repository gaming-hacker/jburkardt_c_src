#! /bin/bash
#
gcc -c -Wall linked_list.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc linked_list.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm linked_list.o
#
mv a.out linked_list
./linked_list > linked_list.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm linked_list
#
echo "Normal end of execution."
