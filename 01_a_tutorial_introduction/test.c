#include <stdio.h>
#include <unistd.h>
#include <unity.h>
#include "01_hello_world.h"
#include "02_temperature_Fahrenheit_to_Celsius.h"
#include "03_temperature_Fahrenheit_to_Celsius_use_float_nums.h"
#include "04_temperature_Fahrenheit_to_Celsius_use_for_loop.h"
#include "05_temperature_Fahrenheit_to_Celsius_use_symbolic_constants.h"
#include "06_copy_stdin_to_stdout.h"
#include "07_count_line_for_stdin.h"
#include "08_count_line_word_char_for_stdin.h"
#include "09_count_digit_white_space_and_others_for_stdin.h"
#include "10_power.h"

static int stdout_bk; 	// is fd for stdout backup
static int pipefd[2];
static char buf[101];

void stdout_capture_start() {
	fflush(stdout);		//flushall();
	stdout_bk = dup(fileno(stdout));

	pipe(pipefd);

	// What used to be stdout will now go to the pipe.
	dup2(pipefd[1], fileno(stdout));
}

void stdout_capture_finish() {
	fflush(stdout);		//flushall();
	write(pipefd[1], "", 9); 	// null-terminated string!
	close(pipefd[1]);

	dup2(stdout_bk, fileno(stdout));	//restore

	read(pipefd[0], buf, 100);
}

void test_hello_world() {
	stdout_capture_start();
	hello_world();
	stdout_capture_finish();

	TEST_ASSERT_EQUAL_STRING(buf, "hello, world\n");
}

void test_temperature_Fahrenheit_to_Celsius() {
	stdout_capture_start();
	temperature_Fahrenheit_to_Celsius();
	stdout_capture_finish();

	char* expect = \
		"0\t-17\n"
		"20\t-6\n"
		"40\t4\n"
		"60\t15\n"
		"80\t26\n"
		"100\t37\n";
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_temperature_Fahrenheit_to_Celsius_use_float_nums() {
	stdout_capture_start();
	temperature_Fahrenheit_to_Celsius_use_float_nums();
	stdout_capture_finish();

	char* expect = \
		"  0  -17.8\n"
		" 20   -6.7\n"
		" 40    4.4\n"
		" 60   15.6\n"
		" 80   26.7\n"
		"100   37.8\n";
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_temperature_Fahrenheit_to_Celsius_use_for_loop() {
	stdout_capture_start();
	temperature_Fahrenheit_to_Celsius_use_for_loop();
	stdout_capture_finish();

	char* expect = \
		"  0  -17.8\n"
		" 20   -6.7\n"
		" 40    4.4\n"
		" 60   15.6\n"
		" 80   26.7\n"
		"100   37.8\n";
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_temperature_Fahrenheit_to_Celsius_use_symbolic_constants() {
	stdout_capture_start();
	temperature_Fahrenheit_to_Celsius_use_symbolic_constants();
	stdout_capture_finish();

	char* expect = \
		"  0  -17.8\n"
		" 20   -6.7\n"
		" 40    4.4\n"
		" 60   15.6\n"
		" 80   26.7\n"
		"100   37.8\n";
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_copy_stdin_to_stdout() {
	stdout_capture_start();
	copy_stdin_to_stdout();
	stdout_capture_finish();

	TEST_ASSERT_EQUAL_STRING("test: hello, world\nThis is awesome!\n1234, 3456, 6789\n", buf);
}

void test_count_line_for_stdin() {
	stdout_capture_start();
	count_line_for_stdin();
	stdout_capture_finish();

	TEST_ASSERT_EQUAL_STRING("3\n", buf);
}

void test_count_line_word_char_for_stdin() {
	stdout_capture_start();
	count_line_word_char_for_stdin();
	stdout_capture_finish();

	TEST_ASSERT_EQUAL_STRING("3 9 53\n", buf);
}

void test_count_digit_white_space_and_others_for_stdin() {
	stdout_capture_start();
	count_digit_white_space_and_others_for_stdin();
	stdout_capture_finish();

	TEST_ASSERT_EQUAL_STRING("digits = 0 1 1 2 2 1 2 1 1 1, white space = 9, others = 32\n", buf);
}

void test_power() {
	int i;

	TEST_ASSERT_EQUAL_INT(power(2, 3), 8);
	TEST_ASSERT_EQUAL_INT(power(-3, 3), -27);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_hello_world);
	RUN_TEST(test_temperature_Fahrenheit_to_Celsius);
	RUN_TEST(test_temperature_Fahrenheit_to_Celsius_use_float_nums);
	RUN_TEST(test_temperature_Fahrenheit_to_Celsius_use_for_loop);
	RUN_TEST(test_temperature_Fahrenheit_to_Celsius_use_symbolic_constants);
	RUN_TEST(test_power);
	/*Following tests cannot be run simultaneously, because there can be only one stdin, as there's only one file descriptor 0.*/
	/*RUN_TEST(test_copy_stdin_to_stdout);*/
	/*RUN_TEST(test_count_line_for_stdin);*/
	/*RUN_TEST(test_count_line_word_char_for_stdin);*/
	RUN_TEST(test_count_digit_white_space_and_others_for_stdin);
	return UNITY_END();
}
