#! /bin/bash
#
gcc -c -Wall fem2d_poisson_rectangle_linear.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc fem2d_poisson_rectangle_linear.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem2d_poisson_rectangle_linear.o
#
chmod ugo+x a.out
mv a.out ~/binc/fem2d_poisson_rectangle_linear
#
echo "Normal end of execution."
