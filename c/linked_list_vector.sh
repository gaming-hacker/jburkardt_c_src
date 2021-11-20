#! /bin/bash
#
gcc -c -Wall linked_list_vector.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc linked_list_vector.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm linked_list_vector.o
#
mv a.out linked_list_vector
./linked_list_vector > linked_list_vector.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm linked_list_vector
#
echo "Normal end of execution."
