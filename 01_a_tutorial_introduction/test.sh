#!/usr/bin/env  bash

gcc -I $unity_path *.c $unity_path/unity.c
./a.out <<- _EOF_
	test: hello, world
	This is awesome!
	1234, 3456, 6789
_EOF_
