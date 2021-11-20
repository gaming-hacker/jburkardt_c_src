#! /bin/bash
#
gcc -c -Wall -I/$HOME/include image_denoise_test.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc image_denoise_test.o /$HOME/libc/image_denoise.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm image_denoise_test.o
#
mv a.out image_denoise_test
./image_denoise_test > image_denoise_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm image_denoise_test
#
echo "Normal end of execution."
