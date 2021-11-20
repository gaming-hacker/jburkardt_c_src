#! /bin/bash
#
h5cc hdf5_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
rm hdf5_test.o
mv a.out hdf5_test
#
./hdf5_test > hdf5_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hdf5_test
#
echo "Normal end of execution."
