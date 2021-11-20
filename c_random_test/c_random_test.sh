#! /bin/bash
#
echo "Execute C_RANDOM tests."
#
./drand48_test.sh
./rand_defect_test.sh
./random_test.sh
./rand_test.sh
#
echo "Normal end of execution."
