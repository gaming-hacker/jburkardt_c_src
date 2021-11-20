#! /bin/bash
#
echo "optimize_test examples."
#
./md.sh      > optimize_test.txt
./md_O1.sh  >> optimize_test.txt
./md_O2.sh  >> optimize_test.txt
./md_O3.sh  >> optimize_test.txt
#
echo "Normal end of execution."

