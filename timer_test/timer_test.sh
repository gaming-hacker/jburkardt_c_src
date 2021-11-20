#! /bin/bash
#
echo "Execute TIMER examples."
#
./timer_clock.sh > timer_test.txt
./timer_omp_get_wtime.sh >> timer_test.txt
#
echo "Normal end of execution."
