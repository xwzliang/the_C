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

sh_test() {
	if [ "$output" == "$expect" ]; then
		echo "test passed."
	else
		echo "test failed."
		echo "Got:"
		echo "$output" | cat -A
		echo "Expect:"
		echo "$expect" | cat -A
	fi
}

# Test for echo
cd 09_command_line_arguments
gcc echo.c -o echo.out
chmod +x ./echo.out
output=$(./echo.out "Hello," "world.")
expect="Hello, world."
sh_test

# Test for find
gcc find.c ../06_pointer_arrays_pointers_to_pointers/get_line.c -o find.out
chmod +x ./find.out
test_string=$(cat <<- _EOF_
	This is awesome!
	01234
	Hello, world.
	_EOF_
)
output=$(./find.out "Hello" <<< $test_string)
expect="Hello, world."
sh_test

output=$(./find.out -x "Hello" <<< $test_string)
expect=$(cat <<- _EOF_
	This is awesome!
	01234
	_EOF_
)
sh_test

output=$(./find.out -n "Hello" <<< $test_string)
expect="3:Hello, world."
sh_test

output=$(./find.out -xn "Hello" <<< $test_string)
expect=$(cat <<- _EOF_
	1:This is awesome!
	2:01234
	_EOF_
)
sh_test
