#! /bin/bash
#
gcc -c -Wall -pg -DDP -DROLL linpack_bench.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -pg linpack_bench.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm linpack_bench.o
#
mv a.out linpack_bench
#
./linpack_bench > linpack_bench.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
gprof linpack_bench >> linpack_bench_gprof.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
#  Clean up.
#
rm linpack_bench
rm gmon.out
#
echo "Normal end of execution."
