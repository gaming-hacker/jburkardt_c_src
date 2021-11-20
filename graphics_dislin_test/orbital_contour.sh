#! /bin/bash
#
export DISLIN=/usr/local/dislin
export LD_LIBRARY_PATH=$DISLIN:$LD_LIBRARY_PATH
#
gcc -c -Wall -I/usr/local/dislin orbital_contour.c 
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc orbital_contour.o -L/usr/local/dislin -ldislin -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm orbital_contour.o
#
mv a.out orbital_contour
./orbital_contour > orbital_contour.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm orbital_contour
#
echo "Normal end of execution."
