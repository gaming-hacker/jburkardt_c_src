#! /bin/bash
#
gcc -c -Wall character_arg.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc character_arg.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm character_arg.o
#
mv a.out character_arg
./character_arg > character_arg.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm character_arg
#
echo "Normal end of execution."
