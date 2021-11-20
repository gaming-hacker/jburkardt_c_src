#! /bin/bash
#
gcc -c -Wall -I/$HOME/include tet_mesh_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc tet_mesh_test.o /$HOME/libc/tet_mesh.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tet_mesh_test.o
#
mv a.out tet_mesh_test
./tet_mesh_test > tet_mesh_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tet_mesh_test
#
echo "Normal end of execution."
