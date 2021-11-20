#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin album_bar.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc album_bar.o -L/usr/local/dislin -ldislin -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm album_bar.o
#
mv a.out album_bar
./album_bar > album_bar.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm album_bar
#
echo "Normal end of execution."
