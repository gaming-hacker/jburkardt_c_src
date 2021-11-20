#! /bin/bash
#
gcc -c -Wall -I/$HOME/include anim.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc anim.o ~/libc/gnuplot_i.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm anim.o
#
mv a.out ~/binc/anim
#
echo "Normal end of execution."
