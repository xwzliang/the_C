#!/usr/bin/env  bash

../../daily_tools/get_h 0*.c > test.h
rm -f a.out
gcc -I $unity_path $unity_path/unity.c *.c ../02_functions_and_program_structure/getch.c 06_pointer_arrays_pointers_to_pointers/*.c
./a.out <<- _EOF_
	343 -689
	This is awesome!
	01234
	Hello, world.
_EOF_
