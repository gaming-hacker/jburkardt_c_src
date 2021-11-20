#! /bin/bash
#
gcc -c -Wall -I/$HOME/include sgmga_write_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc sgmga_write_test.o /$HOME/libc/sgmga.o \
                      /$HOME/libc/sandia_rules.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sgmga_write_test.o
#
mv a.out sgmga_write_test
./sgmga_write_test > sgmga_write_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sgmga_write_test
#
#  Move sparse grid files to dataset directory.
#
mv *_a.txt ../../datasets/sgmga
mv *_n.txt ../../datasets/sgmga
mv *_p.txt ../../datasets/sgmga
mv *_r.txt ../../datasets/sgmga
mv *_w.txt ../../datasets/sgmga
mv *_x.txt ../../datasets/sgmga
#
echo "Normal end of execution."
