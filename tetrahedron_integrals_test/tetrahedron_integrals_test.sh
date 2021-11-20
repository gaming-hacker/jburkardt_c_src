#! /bin/bash
#
gcc -c -Wall -I/$HOME/include tetrahedron_integrals_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc tetrahedron_integrals_test.o /$HOME/libc/tetrahedron_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tetrahedron_integrals_test.o
#
mv a.out tetrahedron_integrals_test
./tetrahedron_integrals_test > tetrahedron_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tetrahedron_integrals_test
#
echo "Normal end of execution."
