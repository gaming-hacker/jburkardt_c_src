#! /bin/bash
#
$HOME/binc/tetrahedron_properties tet_cap.txt > tetrahedron_properties_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

