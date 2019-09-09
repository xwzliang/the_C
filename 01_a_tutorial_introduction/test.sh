#!/usr/bin/env  bash

gcc -I $unity_path *.c $unity_path/unity.c
./a.out
