#! /bin/bash
#
$HOME/binc/gcc_intrinsics >  gcc_intrinsics_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."

