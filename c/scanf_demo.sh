#! /bin/bash
#
gcc -c -Wall scanf_demo.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc scanf_demo.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm scanf_demo.o
#
mv a.out scanf_demo
./scanf_demo < scanf_demo_input.txt > scanf_demo.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm scanf_demo
#
echo "Normal end of execution."
