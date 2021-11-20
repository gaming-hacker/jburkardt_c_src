#! /bin/bash
#
./csparse_test01.sh
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
./csparse_test02.sh
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
./csparse_test03.sh
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
