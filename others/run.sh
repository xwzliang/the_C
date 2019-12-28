#!/usr/bin/env bash

gcc -fopenmp -o hello_world_openmp_parallel.out hello_world_openmp_parallel.c
./hello_world_openmp_parallel.out
