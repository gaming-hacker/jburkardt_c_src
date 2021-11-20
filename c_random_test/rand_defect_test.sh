#! /bin/bash
#
gcc -c -Wall rand_defect_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -o rand_defect_test rand_defect_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm rand_defect_test.o
#
./rand_defect_test >  rand_defect_test.txt
./rand_defect_test >> rand_defect_test.txt
./rand_defect_test >> rand_defect_test.txt
./rand_defect_test >> rand_defect_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rand_defect_test
#
echo "Normal end of execution."
