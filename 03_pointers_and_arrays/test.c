#include <stdio.h>
#include <unistd.h>
#include <unity.h>
#include "test.h"
#include "06_pointer_arrays_pointers_to_pointers/sort.h"

static int stdout_bk; 	// is fd for stdout backup
static int pipefd[2];
static char buf[1001];

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

	read(pipefd[0], buf, 1000);
}

void test_swap() {
	int x = 32;
	int y = 28;
	swap(&x, &y);
	TEST_ASSERT_EQUAL_INT(28, x);
	TEST_ASSERT_EQUAL_INT(32, y);
}

void test_getint() {
	int x;
	int y;
	getint(&x);
	getint(&y);
	TEST_ASSERT_EQUAL_INT(343, x);
	TEST_ASSERT_EQUAL_INT(-689, y);
}

void test_strlen() {
	int x = str_len("hello, world");
	TEST_ASSERT_EQUAL_INT(12, x);
	char arr_char[10] = "0123456789";
	TEST_ASSERT_EQUAL_INT(10, str_len(arr_char));
	char * ptr_char = "This is awesome!";
	TEST_ASSERT_EQUAL_INT(16, str_len(ptr_char));
}

void test_str_cpy() {
	char dest1[11];	// length should be 11! One more for '\0' at the end of string, otherwise test will fail
	char arr_char[] = "0123456789";
	str_cpy(dest1, arr_char);
	TEST_ASSERT_EQUAL_STRING(arr_char, dest1);

	char dest2[17];
	char * ptr_char = "This is awesome!";
	str_cpy(dest2, ptr_char);
	TEST_ASSERT_EQUAL_STRING(dest2, ptr_char);
}

void test_str_cmp() {
	char *x = "01234";
	char *y = "1";
	char *z = "1";
	TEST_ASSERT_TRUE(str_cmp(y, x) > 0);
	TEST_ASSERT_TRUE(str_cmp(x, y) < 0);
	TEST_ASSERT_TRUE(str_cmp(y, z) == 0);
}

void test_sort() {
	stdout_capture_start();
	sort();
	stdout_capture_finish();
	char *expect = 
		"01234\n"
		"Hello, world.\n"
		"This is awesome!\n"
		;
	TEST_ASSERT_EQUAL_STRING(expect, buf);
}

void test_day_and_month() {
	TEST_ASSERT_EQUAL_INT(60, day_of_year(1991, 3, 1));
	TEST_ASSERT_EQUAL_INT(61, day_of_year(1992, 3, 1));
	int m, d;
	month_day(1988, 60, &m, &d);
	TEST_ASSERT_EQUAL_INT(2, m);
	TEST_ASSERT_EQUAL_INT(29, d);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_swap);
	RUN_TEST(test_getint);
	RUN_TEST(test_strlen);
	RUN_TEST(test_str_cpy);
	RUN_TEST(test_str_cmp);
	RUN_TEST(test_sort);
	RUN_TEST(test_day_and_month);
	return UNITY_END();
}
