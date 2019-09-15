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

# Test for echo
cd 09_command_line_arguments
gcc echo.c -o echo.out
chmod +x ./echo.out
output=$(./echo.out "Hello," "world.")
expect="Hello, world."
if [ "$output" == "$expect" ]; then
	echo "test for echo passed."
else
	echo "test for echo failed."
	echo "Got:"Expect 
	echo "$output" | cat -A
	echo "Expect:"
	echo "$expect" | cat -A
fi

