#! /bin/bash
#
$HOME/binc/triangulation_triangle_neighbors box3 > triangulation_triangle_neighbors_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

