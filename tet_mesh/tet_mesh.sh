#! /bin/bash
#
cp tet_mesh.h /$HOME/include
#
gcc -c -Wall -I /$HOME/include tet_mesh.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tet_mesh.o ~/libc/tet_mesh.o
#
echo "Normal end of execution."
