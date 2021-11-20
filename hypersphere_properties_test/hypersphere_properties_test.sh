#! /bin/bash
#
gcc -c -Wall -I/$HOME/include hypersphere_properties_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc hypersphere_properties_test.o /$HOME/libc/hypersphere_properties.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hypersphere_properties_test.o
#
mv a.out hypersphere_properties_test
./hypersphere_properties_test > hypersphere_properties_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hypersphere_properties_test
#
echo "Normal end of execution."
