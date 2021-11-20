#! /bin/bash
#
gcc -c -Wall mesh_bandwidth.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc mesh_bandwidth.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mesh_bandwidth.o
#
chmod ugo+x a.out
mv a.out ~/binc/mesh_bandwidth
#
echo "Normal end of execution."
