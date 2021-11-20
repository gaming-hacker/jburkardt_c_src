#! /bin/bash
#
gcc -c -Wall forest_fire_simulation.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc forest_fire_simulation.o -L/usr/X11R6/lib -lX11 
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm forest_fire_simulation.o
mv a.out ~/binc/forest_fire_simulation
#
echo "Normal end of execution."
