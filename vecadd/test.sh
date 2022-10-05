#!/bin/bash -e

make

n=100000000
echo "sequential"
./main $n 2 3

for((i=2;i<64;i=i*2)); do
    export OMP_NUM_THREADS=$i
    echo "omp with $i threads"
    ./mainp $n 2 3
done

unset OMP_NUM_THREADS
