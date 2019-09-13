#!/usr/bin/env  bash

rm -f a.out
gcc -I $unity_path *.c $unity_path/unity.c
./a.out <<- _EOF_
	12 23 +
	3.5 4.3 -
	5 20 *
	10 4 /
	1 0 /
	10 3 /
_EOF_
