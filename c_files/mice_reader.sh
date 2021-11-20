#! /bin/bash
#
gcc -c -Wall mice_reader.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mice_reader.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mice_reader.o
#
mv a.out mice_reader
./mice_reader > mice_reader.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm mice_reader
#
echo "Normal end of execution."
