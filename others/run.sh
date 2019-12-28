#!/usr/bin/env bash

# If OMP_NUM_THREADS not specified, there are 8 threads by default on my machine
export OMP_NUM_THREADS=16
gcc -fopenmp -o hello_world_openmp_parallel.out hello_world_openmp_parallel.c
./hello_world_openmp_parallel.out
## Output example: (Not deterministic)
# Hello World from thread 4
# Hello World from thread 9
# Hello World from thread 12
# Hello World from thread 1
# Hello World from thread 6
# Hello World from thread 7
# Hello World from thread 2
# Hello World from thread 10
# Hello World from thread 3
# Hello World from thread 5
# Hello World from thread 8
# Hello World from thread 14
# Hello World from thread 11
# Hello World from thread 15
# Hello World from thread 13
# Hello World from thread 0
# There are 16 threads in total
