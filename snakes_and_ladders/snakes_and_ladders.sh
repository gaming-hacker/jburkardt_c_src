#! /bin/bash
#
cp snakes_and_ladders.h $HOME/include
#
gcc -c -Wall -I/$HOME/include snakes_and_ladders.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv snakes_and_ladders.o $HOME/libc/snakes_and_ladders.o
#
echo "Normal end of execution."
