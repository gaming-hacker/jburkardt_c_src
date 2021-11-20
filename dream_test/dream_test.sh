#! /bin/bash
#
./problem0.sh
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
./problem1_main.sh
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
./problem1.sh
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
./problem2.sh
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
