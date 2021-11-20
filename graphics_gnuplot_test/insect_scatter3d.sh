#! /bin/bash
#
gcc -c -Wall insect_scatter3d.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc insect_scatter3d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm insect_scatter3d.o
#
mv a.out insect_scatter3d
./insect_scatter3d > insect_scatter3d.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm insect_scatter3d
#
#  Generate graphics.
#
gnuplot < insect_commands.txt
#
echo "Normal end of execution."
