#! /bin/bash
#
gfortran -c -Wall -I/$HOME/include kronrod.f
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c -Wall -I/$HOME/include kronrod_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  Link the main program and library.
#
#  You can use the GFORTRAN command to link:
#
# gfortran kronrod_test.o kronrod.o
# if [ $? -ne 0 ]; then
#   echo "Errors executing gcc -c kronrod_test.c"
#   exit
# fi
#
#  OR, you can use the GCC command to link,
#  if you include the -lgfortran library,
#
gcc kronrod_test.o kronrod.o -lgfortran -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out kronrod_test
./kronrod_test > kronrod_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
#  Clean up.
#
rm kronrod.o
rm kronrod_test.o
rm kronrod_test
#
echo "Normal end of execution."
